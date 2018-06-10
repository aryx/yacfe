#!/usr/bin/php
<?
	$src = $_SERVER["argv"][1];
	if ($src == "")
		die("you need to specify source directory as a first argument\n");

	$tree = array();

	get_files($src);

	echo "this script looks at macros within single *.c file scope\n";
	echo "it is rather dumb and it CAN produce false-positives\n";
	echo "as it doesn't see any context - feel free to improve it\n";
	echo "used - how many times a macro was used in given file\n";
	echo "defined - how many times #define foo() was found in given file\n";
	echo "\n";
	echo count($tree)." files to parse\n\n";
	echo "used  defined\tmacro\n";

	foreach ($tree as $file)
		parse_file($file);

	function get_files($path)
	{
		global $tree;

		$dir = opendir($path);
		if ($dir === false)
			return;

		while ($file = readdir($dir)) {
			if ($file[0] == '.')
				continue;

			$tmp = $path;
			if ($tmp[strlen($tmp) - 1] != '/')
				$tmp .= "/";

			$tmp .= $file;

			if (is_dir($tmp))
				get_files($tmp);
			else if (preg_match("/\.c$/", $tmp))
				$tree[] = $tmp;
		}

		closedir($dir);
	}

	/*
	 * Tokens statistics are per file here. Thus it is possible that the macro used
	 * in wider context will be shown here as unused etc. Hence we parse only *.c files
	 * as those are rarely included into other *.c files.
	 */
	function parse_file($path)
	{	
		$line_nr = 0;
		$comment = false;

		$token = array();
		$tc = 0;

		$cache = array();
		$cc = 0;

		$file = fopen($path, "r");
		if (!$file)
			return;

		while (!feof($file)) {
			$line = fgets($file, 256);
			$line_nr++;

			if (preg_match("/\/\*/", $line))
				$comment = true;

			if ($comment && strstr($line, "*/"))
				$comment = false;

			if ($comment)
				continue;

			if (!preg_match("/^#define/", $line)) {
				if (preg_match("/^#/", $line))
					continue; /* not interested in other cpp stuff */

				if (strlen($line) > 5) {
					/* this line we should cache */
					$cache[$cc] = $line;
					$cc++;
				}

				continue;
			}

			/* the line starts with #define so lets find the token now */
			$a = 7;
			$b;

			for (; $a < strlen($line); $a++)
				if (in_array(ord($line[$a]), array(32, 9)))
					break;
			$a++;

			for ($b = $a; $b < strlen($line); $b++)
				if (in_array(ord($line[$b]), array(32, 9, 40)))
					break;
			if (ord($line[$b]) != 40)
				continue;
			$b -= $a;

			$text = substr($line, $a, $b);
			if (!strlen($text))
				continue;

			/* update stats in case macro was defined twice or more */
			for ($i = 0; $i < $tc; $i++)
				if ($token[$i]['text'] == $text) {
					$token[$i]['defined']++;
					break;
				}

			if ($i != $tc)
				continue; /* token already known */
					
			/* add new token to known tokens */
			$token[$i]['text'] = $text;
			$token[$i]['line'] = $line;
			$token[$i]['path'] = $path;
			$token[$i]['line'] = $line_nr;
			$token[$i]['used'] = 0;
			$token[$i]['defined'] = 1;
			$tc++;
		}

		fclose($file);

		for ($i = 0; $i < $tc; $i++) {
			for ($j = 0; $j < $cc; $j++)
				if (strstr($cache[$j], $token[$i]['text']))
					 $token[$i]['used']++;

			/*
			 * Interesting tokens arer these which are:
			 * - defined but unused
			 * - defined and used once
			 * - defined more than once
			 */
			if ($token[$i]['used'] > 1 && $token[$i]['defined'] == 1)
				continue;

			echo $token[$i]['used']."\t".$token[$i]['defined']."\t'";

			/* make the output pretty :) */
			echo chr(0x1b).chr(0x5b);
			switch ($token[$i]['used']) {
			case 0:
				echo "31m";
				break;
			case 1:
				echo "33m";
				break;
			default:
				echo "32m";
			}

			echo $token[$i]['text'].chr(0x1b).chr(0x5b)."m'\t";

			$len = strlen($token[$i]['text']);
			if ($len < 6)
				echo "\t";
			if ($len < 14)
				echo "\t";
			if ($len < 22)
				echo "\t";

			/*
			 * the '+' makes vim go to the line where macro was defined
			 * $ vim /some/path/to/some/file.c +1234
			 */
			echo $token[$i]['path']." +".$token[$i]['line']."\n";
		}
	}
?>
