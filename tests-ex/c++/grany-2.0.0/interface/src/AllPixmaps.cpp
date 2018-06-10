/*******************************************************************************
 *
 * Copyright (C) 1999-2000 by Y. Padioleau, G. Cottenceau, P. Garcia,
 *   G. LeGuelvouit, Y. Zemali, S. Crunchant, X. Michard.
 *
 * Please check out README.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 ******************************************************************************/


/*
 * This is a special file which holds all the pixmaps. It will be more convenient to have them here than
 * to read them from several files. (because of the path of installation, etc.)
 */

#include "AllPixmaps.h"


// for BaseWindow

char * AllPixmaps::_dataPixmapNew[] =
{
"11 13 3 1",
" 	c None",
".	c #000000",
"+	c #FFFFFF",
"........   ",
".++++++..  ",
".++++++.+. ",
".++++++....",
".+++++++++.",
".+++++++++.",
".+++++++++.",
".+++++++++.",
".+++++++++.",
".+++++++++.",
".+++++++++.",
".+++++++++.",
"..........."
};

char * AllPixmaps::_dataPixmapOpen[] = 
{
"16 13 5 1",
" 	c None",
".	c #000000",
"+	c #848400",
"@	c #FFFF00",
"#	c None",
"#########...####",
"########.###.#.#",
"#############..#",
"#...########...#",
".@#@.......#####",
".#@#@#@#@#.#####",
".@#@#@#@#@.#####",
".#@#@...........",
".@#@.+++++++++.#",
".#@.+++++++++.##",
".@.+++++++++.###",
"..+++++++++.####",
"...........#####"
};

char * AllPixmaps::_dataPixmapSave[] = 
{
"14 14 5 1",
" 	c None",
".	c #000000",
"+	c #848400",
"@	c #C6C6C6",
"#	c None",
"..............",
".+.@@@@@@@@.@.",
".+.@@@@@@@@...",
".+.@@@@@@@@.+.",
".+.@@@@@@@@.+.",
".+.@@@@@@@@.+.",
".+.@@@@@@@@.+.",
".++........++.",
".++++++++++++.",
".++.........+.",
".++......@@.+.",
".++......@@.+.",
".++......@@.+.",
"#............."
};

char * AllPixmaps::_dataPixmapHelp[] = 
{
"16 15 8 1",
" 	c None",
".	c #000000",
"+	c #840084",
"@	c #848400",
"#	c #848484",
"$	c #C6C6C6",
"%	c #FFFF00",
"&	c None",
"&&&&&&&++.&&&&&&",
"&&&&&&+&++..&&&&",
"&&&&&+&+++++..&&",
"&&&&+&++%%%+++..",
"&&&+&+++@+%%+++.",
"&&+&+++++@%%++.&",
"&+&+++++%%+++..&",
"#++++++@++++.$.&",
"#..+++@%+++.$$#.",
"#+&..+++++.$$#.&",
"#++&&..++.$$#.&&",
"&..++&&..$$#.&&&",
"&&&..++&&$#.&&&&",
"&&&&&..++#.&&&&&",
"&&&&&&&...&&&&&&"
};


// for MainWindow

char * AllPixmaps::_dataPixmapStop[] =
{
  "8 8 2 1",
  " 	c None",
  ".	c #000084",
  "........",
  "........",
  "........",
  "........",
  "........",
  "........",
  "........",
  "........"
};

char * AllPixmaps::_dataPixmapPlay[] =
{
  "5 9 3 1",
  " 	c None",
  ".	c #000084",
  "+	c None",
  ".++++",
  "..+++",
  "...++",
  "....+",
  ".....",
  "....+",
  "...++",
  "..+++",
  ".++++"
};

char * AllPixmaps::_dataPixmapPause[] =
{
  "6 8 3 1",
  " 	c None",
  ".	c #000084",
  "+	c None",
  "..++..",
  "..++..",
  "..++..",
  "..++..",
  "..++..",
  "..++..",
  "..++..",
  "..++.."
};

char * AllPixmaps::_dataPixmapRecord[] =
{
  "8 8 3 1",
  " 	c None",
  ".	c #FF0000",
  "+	c None",
  "++....++",
  "+......+",
  "........",
  "........",
  "........",
  "........",
  "+......+",
  "++....++"
};


// for BordersEditor

char * AllPixmaps::_dataPixmapSelection[] = 
{
"9 15 3 1",
" 	c None",
".	c #000000",
"+	c None",
".++++++++",
"..+++++++",
".+.++++++",
".++.+++++",
".+++.++++",
".++++.+++",
".+++++.++",
".++++++.+",
".++++....",
".++.+.+++",
".+..++.++",
"..++.+.++",
".+++.++.+",
"+++++.+.+",
"+++++..++"
};

char * AllPixmaps::_dataPixmapDelete[] = 
{
"14 13 3 1",
" 	c None",
".	c #000000",
"+	c None",
"..+++++++++..+",
"....++++++..++",
"+....++++..+++",
"+++...++.+++++",
"++++.....+++++",
"+++++...++++++",
"++++.....+++++",
"+++...++..++++",
"++...++++..+++",
"+...++++++.+++",
"+...+++++++.++",
"++.+++++++++++",
"++++++++++++.+"
};

char * AllPixmaps::_dataPixmapLine[] = 
{
"11 11 3 1",
" 	c None",
".	c #000000",
"+	c None",
".++++++++++",
"+.+++++++++",
"++.++++++++",
"+++.+++++++",
"++++.++++++",
"+++++.+++++",
"++++++.++++",
"+++++++.+++",
"++++++++.++",
"+++++++++.+",
"++++++++++."
};

char * AllPixmaps::_dataPixmapArcEllipse[] = 
{
"16 7 4 1",
" 	c None",
".	c #000000",
"+	c #848484",
"@	c None",
"@@@@+......+@@@@",
"@@+..@@@@@@..+@@",
"@+.@@@@@@@@@@.+@",
"@.@@@@@@@@@@@@.@",
".@@@@@@@@@@@@@@@",
".@@@@@@@@@@@@@@@",
".@@@@@@@@@@@@@@@"
};

char * AllPixmaps::_dataPixmapEllipse[] = 
{
"    16    12        5            1",
/* colors */
". c #000000",
"# c #0000ff",
"a c #848484",
"b c #ff0000",
"c c None",
/* pixels */
"cccca......acccc",
"cca..cccccc..acc",
"ca.cccccccccc.ac",
"c.cccccccccccc.c",
".cccccccccccccc.",
".cccccccccccccc.",
".cccccccccccccc.",
".cccccccccccccc.",
"c.cccccccccccc.c",
"ca.cccccccccc.ac",
"cca..cccccc..acc",
"cccca......acccc"
};

char * AllPixmaps::_dataPixmapPolygon[] = 
{
"13 11 3 1",
" 	c None",
".	c #000000",
"+	c None",
"++++.......++",
"+++.+++++.+++",
"++.+++++.++++",
"+.++++++.++++",
".+++++++.++++",
".++++++++...+",
".+++++++++++.",
".+++++++++++.",
".+++++++++++.",
".++++++++++.+",
"...........++"
};

char * AllPixmaps::_dataPixmapClassicalBorder[] = 
{
"    13    13        3            1",
/* colors */
". c #000000",
"# c #bdbdde",
"a c #ef3939",
/* pixels */
".............",
"...#########.",
".a..########.",
".aa..#######.",
".aaa..######.",
".aaaa..#####.",
".aaaaa..####.",
".aaaaaa..###.",
".aaaaaaa..##.",
".aaaaaaaa..#.",
".aaaaaaaaa...",
".aaaaaaaaaa..",
"............."
};

char * AllPixmaps::_dataPixmapGeneratingBorder[] = 
{
"    13    13       47            1",
/* colors */
". c #000000",
"# c #0000ff",
"a c #08ef5a",
"b c #9c1800",
"c c #9c2152",
"d c #9c3163",
"e c #9c4221",
"f c #a50042",
"g c #a5085a",
"h c #a58452",
"i c #ad7b00",
"j c #ad8439",
"k c #b51831",
"l c #b55a63",
"m c #bd8c52",
"n c #bdbdde",
"o c #c65200",
"p c #c6524a",
"q c #ce0839",
"r c #ce7318",
"s c #d62100",
"t c #d63100",
"u c #de5a29",
"v c #de7b21",
"w c #e74a7b",
"x c #e7845a",
"y c #e78c5a",
"z c #f7188c",
"A c #f77b21",
"B c #ff0052",
"C c #ff007b",
"D c #ff087b",
"E c #ff1800",
"F c #ff185a",
"G c #ff2142",
"H c #ff294a",
"I c #ff396b",
"J c #ff398c",
"K c #ff4208",
"L c #ff5221",
"M c #ff6310",
"N c #ff6352",
"O c #ff6b10",
"P c #ff7b52",
"Q c #ff7b7b",
"R c #ff8463",
"S c #ff8c21",
/* pixels */
".............",
".aannnnnnnnn.",
".Baannnn###n.",
".LMaannnn##n.",
".jgCaann#n#n.",
".sJQFaa#nnnn.",
".yuAph#annnn.",
".wKcv#xaannn.",
".r#b#oAOaann.",
".N##HDhqdaan.",
".m###tfrIEaa.",
".RSkjPzileGa.",
"............."
};

char * AllPixmaps::_dataPixmapGrid[] = 
{
"14 14 4 1",
" 	c None",
".	c #000000",
"+	c #848484",
"@	c None",
"@@+@@+@@+@@+@@",
"@@+@@+@@+@@+@@",
"++.++.++.++.++",
"@@+@@+@@+@@+@@",
"@@+@@+@@+@@+@@",
"++.++.++.++.++",
"@@+@@+@@+@@+@@",
"@@+@@+@@+@@+@@",
"++.++.++.++.++",
"@@+@@+@@+@@+@@",
"@@+@@+@@+@@+@@",
"++.++.++.++.++",
"@@+@@+@@+@@+@@",
"@@+@@+@@+@@+@@"
};


// for ZoningEditor
char * AllPixmaps::_dataPixmapFilledRectangle[] =
{
"    16    13        3            1",
/* colors */
". c #000000",
"# c #0000ff",
"a c #ff0000",
/* pixels */
"................",
".#a#a#a#a#a#a#a.",
".a#a#a#a#a#a#a#.",
".#a#a#a#a#a#a#a.",
".a#a#a#a#a#a#a#.",
".#a#a#a#a#a#a#a.",
".a#a#a#a#a#a#a#.",
".#a#a#a#a#a#a#a.",
".a#a#a#a#a#a#a#.",
".#a#a#a#a#a#a#a.",
".a#a#a#a#a#a#a#.",
".#a#a#a#a#a#a#a.",
"................"
};

char * AllPixmaps::_dataPixmapFilledEllipse[] =
{
"    16    12        5            1",
/* colors */
". c #000000",
"# c #0000ff",
"a c #848484",
"b c #ff0000",
"c c None",
/* pixels */
"cccca......acccc",
"cca..#b#b#b..acc",
"ca.b#b#b#b#b#.ac",
"c.b#b#b#b#b#b#.c",
".b#b#b#b#b#b#b#.",
".#b#b#b#b#b#b#b.",
".b#b#b#b#b#b#b#.",
".#b#b#b#b#b#b#b.",
"c.#b#b#b#b#b#b.c",
"ca.#b#b#b#b#b.ac",
"cca..b#b#b#..acc",
"cccca......acccc"
};

char * AllPixmaps::_dataPixmapFilledPolygon[] =
{
"    13    11        4            1",
/* colors */
". c #000000",
"# c #0000ff",
"a c #ff0000",
"b c None",
/* pixels */
"bbbb.......bb",
"bbb.a#a#a.bbb",
"bb.a#a#a.bbbb",
"b.a#a#a#.bbbb",
".a#a#a#a.bbbb",
".#a#a#a#a...b",
".a#a#a#a#a#a.",
".#a#a#a#a#a#.",
".a#a#a#a#a#a.",
".#a#a#a#a#a.b",
"...........bb"
};


// for RulesEditor

char * AllPixmaps::_dataPixmapRed[] = 
{
"    13    13        7            1",
/* colors */
". c None",
"# c #ff0000",
"a c #ff1010",
"b c #ff2929",
"c c #ff3939",
"d c #ffbdbd",
"e c #ffffff",
/* pixels */
".###########.",
"#############",
"#############",
"#############",
"#ceeeeeeeeec#",
"#ceeeeeeeeec#",
"#############",
"#accccccccca#",
"#ceeeeeeeeec#",
"#bdddddddddb#",
"#############",
"#############",
".###########."
};

char * AllPixmaps::_dataPixmapBlue[] = 
{
"13 13 34 1",
" 	c None",
".	c #0000FF",
"+	c #0000FE",
"@	c #1A1AFE",
"#	c #8080FE",
"$	c #1C1CFF",
"%	c #2121FF",
"&	c #4242FF",
"*	c #5656FF",
"=	c #ECECFE",
"-	c #B6B6FE",
";	c #6565FF",
">	c #ECECFF",
",	c #0707FE",
"'	c #8888FF",
")	c #FAFAFF",
"!	c #FAFAFE",
"~	c #8484FE",
"{	c #8080FF",
"]	c #7474FF",
"^	c #D4D4FF",
"/	c #3737FF",
"(	c #1616FF",
"_	c #C2C2FE",
":	c #FFFFFF",
"<	c #EDEDFF",
"[	c #5353FE",
"}	c #0101FE",
"|	c #4B4BFF",
"1	c #F6F6FF",
"2	c #B7B7FF",
"3	c #FEFEFE",
"4	c #C9C9FF",
"5	c #2E2EFF",
" ........... ",
"..+..@#$%&&%$",
"..+.*=-%;>>;%",
"..,')!~&>{]^/",
".(_:<[}|1|%/%",
".2345++&<{&%$",
".2345++%;>>;%",
".(_:<[}$%&{>&",
"..,')!~%/%|1|",
"..+.*=-/^]{<&",
"..+..@#%;>>;%",
"..+..++$%&&%$",
" .........+. "
};

char * AllPixmaps::_dataPixmapGreen[] = 
{
"13 13 18 1",
" 	c None",
".	c #00C600",
"+	c #31CE31",
"@	c #B5EFB5",
"#	c #39D639",
"$	c #10C610",
"%	c #73DE73",
"&	c #DEF7DE",
"*	c #FFFFFF",
"=	c #29CE29",
"-	c #9CE79C",
";	c #BDEFBD",
">	c #5AD65A",
",	c #CEF7CE",
"'	c #EFFFEF",
")	c #8CE78C",
"!	c #18CE18",
"~	c #D6F7D6",
" ........... ",
".........+@#.",
"......$%&**#.",
"....=-****;=.",
"..>,***')!...",
".;***~>......",
".;***~>......",
"..>~***&)!...",
"....=-****,!.",
"......$%&**#.",
".........+@#.",
".............",
" ........... "
};

char * AllPixmaps::_dataPixmapGrey[] = 
{
"13 13 5 1",
" 	c None",
".	c #888888",
"+	c #D4D4D4",
"@	c #FFFFFF",
"#	c #DEDEDE",
" ........... ",
".............",
"..+@.....@+..",
"...@+...+@...",
"...@@@@@@@...",
"...+@# #@+...",
"....@ . @....",
"....@@.@@....",
"....+@ @+....",
".....@@@.....",
".....@@@.....",
".............",
" ........... "
};



// for WarningWindow

char * AllPixmaps::_dataPixmapWarning[] =
{
"32 28 9 1",
"+	c None",
"@	c #6265CD",
"#	c #838183",
"$	c #9C99FF",
"%	c #313062",
"&	c #000000",
"*	c #830000",
"=	c #FF0000",
"-	c #202020",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++",
"+++++++++@@@@@@@@@@@#+++++++++++",
"++++++++$##$#$#$#$#@%+++++++++++",
"++++++%$@$$#%&%#+#+#&&&%++++++++",
"++++++%+@+#****&#$+%#@&%++++++++",
"+++++++%@+**=**%&#+#@&*&++++++++",
"+++++++%@++===*%&$+@+**+++++++++",
"++++++++@+++==*%&#+#%**+++++++++",
"++++++++@+$+=*-&-$+@%+*+++++++++",
"++++++%#@+$$----@#+%%%%%++++++++",
"++++++%$@+$&&&&@%$+@#@&%++++++++",
"+++++++%@+#%%@@%%#+#@&%%++++++++",
"++++++++@+&##%%%%$+@+%%+++++++++",
"++++++++@+&##%%-##+#%%%+++++++++",
"++++++%$@+$#%%%%$#+#%%%&++++++++",
"++++++%$@+#&&&&-#$+%#@&%++++++++",
"++++++#%@+&----&%#+@@&%%++++++++",
"+++++++%@+&%%%-%&$+@#%%+++++++++",
"++++++++@++%%-%-&#+@%%%###++++++",
"++++++++@$$$---%#$#@-####+++++++",
"++++++++++%%%@@@@@%@&###++++++++",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++"
};


// for ErreurWindow

char * AllPixmaps::_dataPixmapError[] =
{
"32 28 9 1",
"+	c None",
"@	c #6265CD",
"#	c #838183",
"$	c #9C99FF",
"%	c #313062",
"&	c #000000",
"*	c #830000",
"=	c #FF0000",
"-	c #202020",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++",
"+++++++++@@@@@@@@@@@#+++++++++++",
"++++++++$##$#$#$#$#@%+++++++++++",
"++++++%$@$$#%&%#+#+#&&&%++++++++",
"++++++%+@+#****&#$+%#@&%++++++++",
"+++++++%@+**=**%&#+#@&*&++++++++",
"+++++++%@++===*%&$+@+**+++++++++",
"++++++++@+++==*%&#+#%**+++++++++",
"++++++++@+$+=*-&-$+@%+*+++++++++",
"++++++%#@+$$----@#+%%%%%++++++++",
"++++++%$@+$&&&&@%$+@#@&%++++++++",
"+++++++%@+#%%@@%%#+#@&%%++++++++",
"++++++++@+&##%%%%$+@+%%+++++++++",
"++++++++@+&##%%-##+#%%%+++++++++",
"++++++%$@+$#%%%%$#+#%%%&++++++++",
"++++++%$@+#&&&&-#$+%#@&%++++++++",
"++++++#%@+&----&%#+@@&%%++++++++",
"+++++++%@+&%%%-%&$+@#%%+++++++++",
"++++++++@++%%-%-&#+@%%%###++++++",
"++++++++@$$$---%#$#@-####+++++++",
"++++++++++%%%@@@@@%@&###++++++++",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++",
"++++++++++++++++++++++++++++++++"
};


// for AboutWindow

char * AllPixmaps::_dataPixmapAbout[] = {
"119 124 64 1",
" 	c None",
".	c #070504",
"+	c #18921A",
"@	c #8C8C83",
"#	c #224A1C",
"$	c #9BC38C",
"%	c #D58553",
"&	c #8A522E",
"*	c #0DB30B",
"=	c #86A634",
"-	c #427A44",
";	c #BD7242",
">	c #D1A78C",
",	c #4EB218",
"'	c #202A24",
")	c #E3EAD1",
"!	c #CFCECA",
"~	c #02C204",
"{	c #AC8673",
"]	c #866C54",
"^	c #704627",
"/	c #ACAAA3",
"(	c #563624",
"_	c #F28B4C",
":	c #626963",
"<	c #575851",
"[	c #D77A41",
"}	c #21BA14",
"|	c #737874",
"1	c #DCB8A5",
"2	c #FCCAA6",
"3	c #B2B8A4",
"4	c #4E901E",
"5	c #8A922C",
"7	c #52A644",
"8	c #1E1A15",
"9	c #6AAE2B",
"0	c #395740",
"a	c #7A867C",
"b	c #FEE2BC",
"c	c #393936",
"d	c #B0977B",
"e	c #AE795B",
"f	c #A75F34",
"g	c #C6CCB7",
"h	c #2AAC26",
"i	c #C9996D",
"j	c #FDA972",
"k	c #8DA87C",
"l	c #E6DAC5",
"m	c #FEB98A",
"n	c #402A19",
"o	c #FAFAE4",
"p	c #9A9E8C",
"q	c #765746",
"r	c #FD9655",
"s	c #965E44",
"t	c #3A8E14",
"u	c #8D7A6D",
"v	c #45BB16",
"w	c #484547",
"x	c #6B9E74",
"y	c #6B3C1F",
"z	c #9EAE8C",
"           >i_%__%[;s8]mie;((8..;______[[[;&.eiq.^_r______r_r___[&.immm.qr__[[[[;s^n.:22mjjjrr;.frr__[[[[s]|           ",
"         i8..^;[[[;&8(2mjjjrrjrn8r___[[[;fy8rmjjjs.&____r_rrrr__[y8mmmm&8r__[[[fsyn.nb2mjjrjrr_n8rr_[[;f&n8>m1         ",
"        rrj_^..n;f&882mjjrrjrrr;.&_[[;;f&8nrmjjjjj_n8;_________%;.q22mjr.s_[[[fsy8..12mjjrrrr__[.y_[;f&n.ymmjjj1       ",
"       rrrrr__.s.y881mjjjrrrrr__y..nyysn.ymmjjjrrrrj&.y[[[_%_%[[&.>2mmjr(8__[f&y.8yy2mjjrrrrr___^.......]mmjjrrr>      ",
"      rrrrr__[.j_8.{2mjr_r_rrr__[.r;^(..]mmjrrrrrrrrj_8.^[[[[[[;nnb2mjrrf.[[sy.n[jsw2jjrr_rrrr__%.rmjjr.2mjjrrrrr>     ",
"     rrrrrr_%[.jjsw2mjjrrrrr_r__[.mjjrr.mmjjrrr_rrrrrrr&.8s;[ffs.]2mjrr[[8n&.n[jrrn{mjjrrr_r_r___(&jj__.mmjjrr_rrrl    ",
"    jr_rrr__[;.jr&^mmjrrrr_rrr_[f.jjr__8imjrrrrrr_rrrrrr[8.......22jr__;[y.nimjrr[nemjr_rrrrrrr__s8rr_[.mjrrrrrrr_i    ",
"    rrr_r__[[s.jrn{mjjrr_rrr__[;&.rrr_[(sjjrr_rrrrr_rrr__[.jj_;8{2jj_[;&^w(wmjj_[;.mjjrrr_rr_r__%[8;_[f.mjrrr_rrr__g   ",
"   >______[[s8.%rnemjrrr_r___[;sy.r__[[^(jrrrr_rr_rrr_r_[[.r_s8.>e;^cnnnw<a]jr_[;s.jjrr__r_rrr__[[nysn..;jjrrr_r__;e   ",
"   r[[[[[[;s8.e8r.jjjrrrrr_[[;s(.........;jjrrr_r_r_rr__[f._&.{^s^ncnc'w:/|&rr[f(..&rrr__r__r___[f8.n]>w8_rrrr__[[fq   ",
"   [[[[;ff&8.{2r^.jjrr____[[ffn.8{mmmmjj(.rrrr_rrr_rr__[f&.yn1sncnc'ncw:p3<;_;y.q>s.([_________[;n.{2mjr.8_r___[[;^8   ",
"   fffs&&^8.{2mj&.&rrr__[[;f&n.^>2mjjjjrr.8_rrr_rrr__[[;^8.q;('wwcnccw|dgpc;88]mmjjf8.;______[[;8.{mmmjj_8(r__[;f&8.   ",
"   ........{2mjjr&.8[_[[[f&y..]22mjjrrrjr_.8_rrrr___[[;&.8d&cc(cccccw:p3/:'n/b2mjjjr_8.8f_[[[[;8.emmjjrrrs.n_[;sn..{   ",
"   (mmjjr&q2mjjrr_[8.y;;f&8nyw2mjjrrrrrrrr%8(rr___[[ffy.81^w(cw(wccw:p33|c'b22mjrrrr__.%n8f[;fn.emjjjrrrr_&.&&88&_.2   ",
"   wmjjr_.1mmjjrr_r_&..yn.sjf^mjjjrrrrrrr_rs.(__%[;f&8.w%(wwwwwwccw:@3gp<'(b2mjjrrr___n;j[88^8.emjjjrrr___[n.n{jjr.2   ",
"   sjjr[yq2mjj_r__r__[8.qrjrnemjjrrrr__r_r_rs.y[[f&n..u[(c^w^wwwcw<apg/|w8;bmjrrrr_r__^^jjr[n.emjjrrrrrr__[^w2mjr%.m   ",
"   ;jr_;.>mjjrrr_r____%.mmr_nemjrr_r_rrrr_r__^.^&8.^^ubnw<<yqwwwc<|p3g@<''2mjjr_r_rr__;njjrr_8imjjrr_r_rr%[yqmjr_[.m   ",
"   [r%[(qmjjrrrrr_____[.rjr[.jjrrrrrr_rrrrr___n.nej%.b(w<q]<<wwcw]p3gz:c8^2mjrrrrr_r__[.%rr__fnjjjrrrr_r_[;8;jr_;s.m   ",
"   rr;f.rmjrrr_rrrr___[8;r[f.jjjr_r_rr_rr_rr_%[.mjjy!&w<]]]]<<ww:@/g3a<'8[mjjr_r_rrr__[n&__[[[n&rr_r_rr__[;._r_sn..m   ",
"   [&n..sjrr_r_r_r___[[(y_f..;jjrrr_rrr_rrr___[.jr[{sw<;{{{]qww<|zg3@:c8n2mjrrrrr_r__[[yn_&&nn..[rrrr___[;s.;^.n&i.e   ",
"   8we>^.nr___r_rrr__%;yn^8iq.(r___rrrrrr_rr_[;.r_8;c^]>ii{]<ww:p3gz|w'8;mjjrrr_rr___[f8..wyeej88r__r__[[f8.n]>mjrn(   ",
"   2mmjj;.8[______r__[;n.q2mj;.(r_r__rrrrrr__[f._smww]iii{i:<w<azg3a<'8'mmjr_rrr___[[f.8e22mjjj;.&_____[;y.u2mmjr_&.   ",
"   mjjjrj;..[[_______[;.q2mmjr[.n[__________[[s.[.;w<]ii{>{]ww:p33p:c88&mjrrr_rr__%[f.n>mmjjjrr_y.n&[[[f&.w2mmjjr_[.   ",
"   jjrjrrr%..s[[____%[(.!2jjr_[[n.[________[[f8...^wq{{{i>{:w<|pg/|w'88mjrr_____[[[^.qmmjjjrrr_%&(i&.8^&.812mjrr__[n   ",
"   jrr_r__r_n.8f[_[%[;.q2mjr_[;s8..;[____%[[f8.db;wwq]{i>>{<w:@gg@<c88&8[r____[[[;y.;mjjjjrrr__[yqjjj[y..>2mjjrrr_[&   ",
"   jrrrrrr___.%n.&[[;y.12j_[[&8.8;n.&[[[[;;s8.{2m^ww]]{ii>]w<|pgp|w888rn.y[[[[;;fnnrjjrrrrrrr__[nejjjr_sy2mjjr_rr_[[   ",
"   jrr_rrr___8%j_^.(s.q2mr_fn.n[_[;n..nn^^s8.{2mjwwwq]]{p{q<:@3g@<'88ejj&..&ffs&8&rjrrrr_______[.jjjr__&wmmjrrrrr__[   ",
"   rrrr_r____y&jjrr&..1mj[y.8%r_[;&.;[;&;;..{2mj[cwwqq:u{|]<|pg/:c88^rrrr%n......8&[__________[f.jjjr_%nemjjrr_r___[   ",
"   jrrrrrrr__&(jrr_[f.2j&.8%jr[;s<^wccccn''n^sj_sc(w<<q]||::@3g@w888;ss^('n'nnnn&;%.&[[[[[___[[^(jrr_[[8emjr_r_rrr[[   ",
"   jr_r_rr___%.jr_[s8.s8n[;q<wwwwwwwwwcccnn''''^^cwwyw<qau:|d33:'88'nnn'n'n'''c'c'cn;n%%%_[_[[;8fjr_[[;.jjjr_r____[f   ",
"   jjrrrrrrr_[8[r_f.e.iqq<<<<ww<wwwcwwcwcwcc''888'cwww<<::q|pg|c88'cn'cn'c'ncnccccccc([[_[[[;fs.[r_%;;s.jjr_____[[;&   ",
"   jrrr_r_r__[n&_&8>j;<<<q<q<q<w<wwwwwwwwwwwccn'888ncwwq]:qa/3<88'n'cn'c'cccccwwwwwwwcc&[%[[;s&.rfsyn8..^___[[[[[;s8   ",
"   jjr__rr__[[ynyw2%{/iaq<<<<<q<<<<<<<<<0<<<wcccn8888cw<qq:@3a'88ncn'ncccwcwwwwwwwwwwwccw&[;sy...wy]eims..f[;;;ff&8.   ",
"   jjr___r__[;n.]22ibob>d]:<:<<:<<<<<::::<:<<wwcccn'88c<]<:p@c88c'ncccwwwwwww<<<<<0<<<wwcw[&8.ni22mmjjjj_8.........{   ",
"   jrr_____%[^.{2[{1bo!>|:|@]::::::::::::::::<wwwcccn88w<<]@'88wccncwwwww<<<<<<<:::::<<wwwcsn>22mjjjjrjrrr.jmjjjrr.2   ",
"   8&r___[[[&.{2i:i2ob1>||a@pp]:|]:::]::|||||:<wwwwcc''8w<:w8'ww'ccwww<<<<:::::]:||||||:<www&m2mmjjrrrrr__y&jjjjr_.m   ",
"   %^.nf[[;s.{22]{>bob1{||@p/33@@@a||||a@a@@@::<<<wwwcn''wc.'<wcccww<0::::::]|||a@@@p@@|::<<w<mmjrrrrrrrr_fnjjjr_[.m   ",
"   jjj;8.n&8db2mqi2bo21d:|@p/3gg3p/@@ua@pdp@pa::::<<wwccn'''8cwncww<<::::|||aa@@p@pzp/pp@@|:<w<jjrrrr_r__[[._jr_[;.m   ",
"   jjrrr_&..b2m[aib)b2/{|u@p33g!lgg3pk{pppz/3pu||:::<wwccc'n'''www<<:]|||||@@p@pp/33ggg333pp|:w<jjr_rr___[;(^r_%[s.j   ",
"   rjrr____.mmj]{1bob!>@|a@/33g!)))!3////3333zp@@||::<wwwwcccc'cw<<::|aa@@@p@ppp33gg!!l)l!gg3p|<&jrrr__[[[s&8r_[s8.%   ",
"   8&r____%.mjr]p2bob1/au@@p3gg!))oo)g33gg3ggg/pp@@||:<<wwwwwcccw<::|a@@p@pp/p333g!l))))o)o))!3p:;j___[;fss&.;_&8{n.   ",
"   iq.nf_[[.j_[ud2bob1daa@p/3gg!!l)oo)ggg!!g!!3/zdp@|||<<<<<wwwcw::||a@ppppp333gg!l))!)!!!!!))))g|%_[;;ssss&yny^12>8   ",
"   22m;n.(f.__]|>2bbb/p@u@pp33!!)))ooo))l))l))gg33pp@a|::::<<<www<||a@ppp/3333ggg!!!gg3333z/p3gg)lp[;f&&&&y8..]2222i   ",
"   b2mjjrs...8]{i2bo!3dpa@p33g)!)))oooooo)o)))l!g33zpp||||::::<<<<|a@p@p/33ggggggggg333zp@@@a|aa@3/{&^y8..8({1b22mmj   ",
"   2mmjjjjjj.&]a>!ob23/@a@/33g!))))oooooooooo))!gg33/pp@@a|||::::<:a@ppp33g3gg!gg3333zpp@a|::<<<<<<w[.8({12b22mmmjjj   ",
"   mjjjjjrrr.j|{>2bo13/@d@/3gg!l))oooooooooooo))gggg33ppp@@@a||::::@pp//33ggg!!gg333pp@a|::<<wwcccc'&.2b22222mmjjjrr   ",
"   mjrrrrrr_.j|{/!bb!3/@@p/3ggl))oooooooooooooo)l!!gg333/ppp@@@aa|:appz333gg!!gg3333/p@a|::<0wcccc''j({2222mmjjjrjjr   ",
"   jjrrrr__%.j|{>2obg1/@dpp3gg!)))ooooooooooooo)!!g!ggg333/z/pp@@@aupz33gggg!!g33/33p@@|::<<wwc''8n[r&q222mjjjjjjjjr   ",
"   jrrrrr__[.j|d1!bb!3/@@p/3gg!))))oooooooooooo)!!gg!gggggg33/z/pp@@p/333gg!ggg3/pzpp@||:<<wcc''8&mjr%822mmjjjjjrjrj   ",
"   jr__r___[.j|d/1bl!3p@@@/3gg!l)))ooooooooooo)l!g!g!g!ggggg3333//ppp33ggg!!ggg3/p@@@||:<<wwc''&[mjj_[.>mjjjrjjjjjjr   ",
"   r_r_r__[[.j{d/1lb11p@u@/pggg!))))oooooooo))))!g!ggg!!!!gg!gg3333/z33gggg!ggg/p@aa|]:<<wcc'&f&.jj__[n]mmjjjrjrrr__   ",
"   r_____[[f.iu{/1ll1z}7a@@/3g!}x$)))oooooo)o))!!gg!g!!gg!g!g!!!!g3333gggg!glgg3pa||::<<wcccsf&y.rr%[;y(jjjjrrrr__%[   ",
"   __[[[[;s&.ra|d/!l3~~h|upp3gg~~~~}$))o)o)))))!!,}gggg!gg!!g!!!!!!!g3ggg!gggg3/p@||:<-0wc'&&^y8.rs&n8..&jrrr_%%[[[;   ",
"   %[[;;fs&^.;uad31g}~h|::a@33g~~~~~~}g)))))))l!!}~hg3ggg!g!g!!!!!!!!!gg!gg!gg3zpa|:<<~~~*n^y(8...yw{emq.(__%[[;;s&y   ",
"   [[;ff&y...n:|d>g}~*a:<<|@/3g~~~~~~~*$g!))))l)$~~~kz33ggg!g!!!!!!!!!!!g!!g!g3ppa]:<<~~~~;%...i7iimmjjj;..f;f&&(..8   ",
"   %[;f&8n[.b2q:|d7~~k|<ww:a/3g~~}|h~~~~z3!!ll)!}~~~}@@/3g!!$$!!!!!!!!!!!gg!ggg/@a::<w*~~~e;;[^}~~}jjjrrj%8.^&8.^%.o   ",
"   [;&8n[jr.22q:ap~~7a:wcw:a/3g~~h:w:~~~}@$g)llg~~~~~-|p/gg!$}!!!!!!!!!!gg!g!g3ppa]:<w*~~~&&s;%~*},rrrrrr_[n.8ejj_.b   ",
"   s8n[jjr_.mm]q|h~}p:<wc<:@p3g~~h<c'-~~~|@pg!)k~~~~~*<|p3g!$~vgggg!!!!!!!g!gggp@a:<<w+~~~^n&;t~},drrr_rrr_%.m>r_[.b   ",
"   nimjjrr_.mj]:|~~x@:www<|@p33~~h<ww:~~~7<@3g)}~~~~~~0<az3!$~~933g!!!!gg!g!!g3/p|]:0w+~~~^nn;~}v9[_r_rr___[.jj_[;.2   ",
"   rmjjjr_[.jj]<h~}p|<w0<:|@z/3~~7<w<:~~~hw|pg$~~~~~~~-w:pgg$~~~x{/3!ggg!!!!!g3zpah+0w+*~~(nn4}v9drrrr_rr_%[.r__[&.2   ",
"   sjjrr__%.jj;:~~7|:ww<<:|@p/3~~7:w:a~*~hc<a3k~~~|*~~*'<@zg$~~~}|@z3g!!gg!!gg3/pa~**w#~~~t8y}}v=[r_rrrr_[[;._[fy..2   ",
"   8rjr__[[.jj;+~*::<w<<::|@@/3~~x<0:p~~*hcw|z}~~*<-~~~0w:z3$~~~~h|@3ggg!g!!!gg3{h~~+cc~~*wn4}v9drrr_r___[;&.fn.&r.{   ",
"   (;r___[[.mj;*~*:<w<<:::-@@/z~*x:<|k~~~-cw|z~~~7wc~~*-c:k3$~~~}~:|p3g!g!gg!g33p~~~0n'+~~4n*},=[r__r___%[&8.n{2mjny   ",
"   nn___[;;.jj;~~t<ww<::h~~|@@/~~x:<|7~~~|cw:x~~~:w'h~~*c<a3$~~~*~}<apggg!g!g!g37~~*c'8+~*w^}v9d_____%[[;^..i2mjjrs.   ",
"   ...nn&&f.jj7~~-ww<-h~~~*:|@p~~a:<|}~~}:cw:7~~*:cc-~~~ww|p$~~~-~~h:@3ggg!!ggg3~~~-'88#*~t*~,9[__[[[[[;n.w1mmjjrr%.   ",
"   q>me;((..rj}~~0c0*~~~~~+<<:@~~a::7~~~7wcw:h~~}:cw:~~~0w:pk~~~-*~~-:p3ggggggg7~~~0'888~~}*},d.f[[;;f&..{mmmjjr__[n   ",
"   mjjjjjj_.sr}~~#cc~*-:~~+cw<:~*a::*~~*|wc<a~~~~~*h7~~~-c<@k~~~:0~~*:ap3g!g!gg}~~*c'88'****v,[8..8y&n.n>mmjjjrrr_[&   ",
"   jjjjrrr_ynj~~~#'':::<~~+'cw|~*|:h~~~x<cc:x~~~*}~~*~~~-c<|k~~~:'*~~*:@/ggggg7~~~-n88''+~~},=_&w>;(..q2mjjrrrr____[   ",
"   jrrrrrr_f.[~~~#''w::<~~+8'c-~hah~~~7:wcw|k~~~:c'0h*~~hn0|k~~~-'w~~~-|p3gggg}~~*w'8'''+**}9[[&(mjjj.2mjjrr_rrrr__[   ",
"   rrrrr___%8^~~~#8'w::<~~+8'c:~hh~~~h|<ww:@7~~h<n'c<~~~+nw:x~~~-cch~~~||p3gg$~~~hc'8'cc#*}v5[;^(mjrrnejjjrrr_r_r__[   ",
"   rr_r_r__%y.}~~+8'w:|:~~#''#:~~~~~7:<ww<a/7~~xwccw<h~~*'c:k~~~-cc0~~~*:a/gg}~~~-''''cwc~},[%;n;jjrr&^jjrrr_rrrrr_;   ",
"   rrrrrr__[f.7~~~8'c<||~~+'8c-~~~*-wwww<|pg}~~|<cw::7~~~'c:x~~~h'c<h*~~h:p3k~~~*w''ccwwc*}=[[;8ejjr_[.jrrrrr_r_r_[f   ",
"   rr_____[;sni~~~#8c<||~~-'cc:~~*0wwcw<:p3!}~}|ww<apk~~~'c<x~~~hnc<|~~~~:|z~~~~hc'8cwwww+}5;_;n;jr__[._jrrrrrr_[[;s   ",
"   r___[[[;sy.i~~~*8'w:a~~-''c-~~~-'cc<:p3gl~~7|<<:p33~~~cc<x~~~*nc<a7~~~*:7~~~~:c'nw<<wwt}5;%;.jrr_[[n&r_r____[[fsn   ",
"   __[[[;s&n.nit~~*#'w<|~~0c'c-~~~*c'w:@3g!)~~k:<<a/gg}~~wc<x*~~~cc<|p*~~~h*~~~*w''c<<<<w+h4f_;.rr_[;;^(rr_r__[;f&n.   ",
"   _[;f&y8..8rmi~~~~''<:*~0c'c+**~~*c<|z3!)l~~p|<:@3gg7~~ww<x~*~~nc<@zx~~~~~~~~-c''w:::<<0},f[;.rfsyn8..n[__[[ffy8.]   ",
"   f&8..(f^&inj;7*~~*'w:h~:c'c-~+*~~-<a3g!l)~hz::|p3gg$~~<w<x~~~~'c<|z3}~~~~~~~0''w<]|::<-}v&[f....(s;m%n.8s;s&n.;.2   ",
"   8(erjrr.rm8&r[}~~~*0w*~:#cc+~+:*~~0|pg!!)~xz|:a/ggg$~}:w<x*~~~0'wa/3k~~~~~~*8'nw:|||:<w~}<s[.m8rmjjjjj[n.8n8yrj.m   ",
"   mmjjr_yqmmr._r;*~~~~+*~:ccw-~+w*~~*:@3g!l~$z||p3gg!g~h:<:|~~~~0'wa/33}~*~~~088c:a@@a]:<~*<^fnii^jjjjjrjr;8.]2j_.m   ",
"   mjrr_[.>mjj^n_%;*~~~*~~wcc0+**w0~~~h:@gg!~gpa@zg!!gg}h|::x~~~~0'wu3g3z~~~~~'.'w|ppp@||:*~tn^f_mn{jrrrrr__&^mjr[.m   ",
"   jj_[;nqmmmjr8f_[;+*~~~~ccc<-~+wc*~~~-apg!}g/@p3g!)gg}h@|:a77hh0'w|zggg7~~~+.8'<@z/ppu||*~+ncy;mr8rrrrr__[yqmr_;.j   ",
"   rr[fs.>mmmjr&.[%;^#*~~~''c0h~*cc-*~*~|a3gxg3p/g!!!!g77p||ppz|wccw|z3ggz*~~088c:p33/pp||+~*cncwsm&[rrr__[[8;j_s8.r   ",
"   [&nn..immjjr_8y[;;c'+*~88c<+~~ccc*~~~~|@3!g3z3g!)!!!7xz|ap//@:ww:a/ggg37~~'8'w|p3g3zpp@h~~c'cnw<s8rrrr_[;.__yni8n   ",
"   8y]ejnnmmjjrr;.&f&&c'8#8'c<*~~w'c-~~+0w|/ggggg!))!!g$$z@@z33pa::|p3gggg3}hc'c<@3gg33ppp7*~0ncwww<<<;r_%;s.&8]2m%.   ",
"   22jjj[.&jjjr_%y.^^.wc''8'w:h+*#'c0+:c'c<@3gggg))l)!g$$3pp/3333pp/33gggg3x7<ww|p3g!g333/k~~-cw<::::|u:_[s8.q1mmjj8   ",
"   mjjjrry._jrr_[;.8y.;wcccc0:|::wc#w:<wcw<@3g!))lo)))gg$3pz3gggg333gg!!g!g3{|<:@zgg!ggg!g$}h|w<:@{z3g!|[;8.{2mmjj_f   ",
"   jjjrrr_.8jr_[[;y...w<w0w<::||:wcw<::<<<:pg!)))oooo)ggg33/3ggggggggggg!ggg3@uap3ggg!g!))!gza::@3g)))3:[88>2mjjjrr_   ",
"   jr_r___f.&_s&n.(f&(2%w<<:<||||:<<0::::|@/g!l)))))))ggggg3gggg!g!!!!g!ggggg$pp33g!!g!g))))gpa@3!))!z:(n812mjjrr___   ",
"   r_rrrr_[n.8(erjjr8imr]w<::||@|::::::||ap3g!!)))))!ggggg3gggg!!g!gg!g!gg!gg313gg!gg!g!!o))!3pz3gg/@]www2mjjjrrrr__   ",
"   rr__r__[;.mmjjrr;8m2j_<<:::||:|||:::|a@pz3g!!!!!!!gggggggg!gg!!gggggggggggggggg!!!gggggggg3/pzp@a|wws22mjrrrrrrr_   ",
"   rrrr_r_[f.jjjr__y&mmjj[<<:<||@|||||::|a@p/3gg!g!ggg3g3ggggg!ggggggggg3g3gggggggg!!gg333g33/p@@@|:wwc%2jjrrrr_rrr_   ",
"   rrrrrr_[f.jjrr_[.rmjjjrqw<::||@|||::::|a@p/3$gggg33gg3ggggggg3g3333333333g33ggggg!g33//zzpp@@|:<wwc&mjjrrrrrrr__[   ",
"   _r_rr_[[f.jrr_[&8jjjj___w<<<:||||||::::|a@@//3$g33333333ggg3333333/33/3z3333333gggg3/zpp@p|a]:<<wcc%mjjrr_r_r__[;   ",
"   rrr_r_[[n.8f_[[n&jjrr__%ew0<::|||||:::<:||@@//3333333333gg3333////zz//p/z/3/3/333gg3/p@@@a|::<<wwcwjjrr__r___[[;f   ",
"   _rr___[&.qiy.(s.jjrr_[[[[qww<::||||::::<::aa@@//33/z3/333g/p/ppzppppppppzpz/p/zz3gg3p@@a||]:<<wwcc&jjr______[[;fn   ",
"   r___[[;8822mr]...8((s&s;;fwwww::|||:::::<::|a@@ppp///z/p3gzppp@@p@@@@@@p@dpppppp/3g/p@||||:<<<wccn.8[__[_[[[fs&n.   ",
"   ___[[;y.{2mmjjjj%e;((n..8&%ccw<:::|:::<:<<<::|a@@ppzppp@$gd@p@@@@@@@@a@@@@@p@p@@p/g/@a|]::<0wwcccs3n.8f[;;s&^8..s   ",
"   _[[;fs.n2mjjjjjjjjjjjjf(in8eccww:::::::<<<<<::|aa@@p@p@@p3paa@aa|||||||a@@@@@@@@ppg3@||<:<<wwcc'nbb2in.8^^n.n&_.2   ",
"   %&&n8..>mjjjrrrrjjrjrrysjj[8sccc<<<:::::0<ww<<::||a@@@a@@g@|||u||:]|::||||a|aaa|a@33@::<<wwwcc'';b22mj[8.ns>jjr.m   ",
"   .((;;r.2mjrrrrrrrrrrr_nejjr_.<'cc0<:::::<<0www<<::|||a||@3|:|::::::::<<::::||||||a3g@:<<wwcc'''^b2mjjrr_.2mjjr_.m   ",
"   mmmjrr.2jjrr_rrrrrrr__.jjrr_8iw'ccw<:::<<<w0cww<<::::::|a3:<<:<<<<<<w<<<<<<:::|:||zga:wwwccc''nb2mjrr__%.mjjr_[.j   ",
"   mjjj__.mmjrrr__rrr___snjjr_[n]mw'ccww<::<0wwccccww<<::<<|/:w<<<wwwwwwwcwwww<<:<:::pg@<wwcc''''%2mjjrr__[.jjr_[;.j   ",
"   ;jrr_[.mjjrr_rr__rr_[^njr_[[^(jjc''cww0<<w0ccc#cccww<<<w:@<wwwwcccccccccccww<<<<<:|g@0cc'''''s2mjrrr__[;.rr_[fs.j   ",
"   ;rr_[;.mjrrrrrrrr__[[nfr_[;y..;j%''''cww0ww0cc'ccccwwwwc<awccccc'''''''''c'cwww0<<:3pwcc''88&mmjjrrrr[[f.r_[sn..;   ",
"   nr_[;f.mjjrrrrr___[[f._r[(.q1w.;rr''''ccwwwccc'''''cccwcw:c'c'''''8'888'88''cccwww<a@cn''8'^2mjr_r___[[s.;y.n]r(.   ",
"   n[s(8..%jj______[[;;s.;88]22mm(.f__n8'''ccc#ccc'''''cccccw''''8888888888888'''ccwcw<:c'8'8^mjjr______[f8.n]>mmj_8   ",
"   .8y]em8._r__[[[[;fsn..ni22mmjjj(.s_%c88'''ccc'''''8''c'''c'888888888888888'8'''cccccc''88n.n[_[____[[f8.{2mmjjjr_   ",
"   e2mmjj_8(__[[;;s&n..q>2mmjjjjr__n.8^;^8'8''''''''8''''''''888888888.88888888''''''c''888n2rs.8f[[[[[;8.{2mjjjrrrr   ",
"   mmjjjrrs.^;;fs^8.8]22mmjjjrrr__[&(i&88q88'8''''8''8'88'88888888888.88.88888888''c''8888n2mj%8..8&;ff8.{2mjjrrrrr_   ",
"   jjjrrr_%y......n>22mmjjjrjrrr__[y&mjj;y;8888888'8888'8888888.88...8.88.888888888888888nmmrs..[.[88^8.{mmjjrrrrr__   ",
"   jrrrrr__[.mjjr.b2mmjjjrrrr_rr_[;8;jrr_[^ec88'8888888888888888.........88888888888888.n2m_(.(jj.jr;8.{2mjrrrr_rrr_   ",
"   rrrr_r_%[.jjjr.2mmjjrrrr_rr___[;._j__;s.n&&8888888..........8(s[jr[c.88888.88888..8.w2m;.8emr_.j__&y2mjjrrrrrr_r_   ",
"   rr_rr__[;.jjrr8imjrrrrr_rr_r_[;s.rr[;f.{iq.%c..88.8......8&;mjrr_%[[[^...8888.....8s2m(.(>mjr%.rr_&wmmjjrr__rrr__   ",
"   rrrrrr%[f.jrr_n;jjrr_rrr_rr__[;8.......2mmj;(;c..8..8'^s[n..nnnnn&&&&&e'.8...8..8c22i8.{mmjr_y.[__nemjjr_rrr_r__;   ",
"   jrr_r_[;s.rr__(sjjr_rr_rrr__[;y.e2mmjr.mmjjrrr&8&&;[8.n[ryrm%e;;;((((8..sn8888ws%22q.n>mjjj_f.q.[_nemjrrrr_rr__[&   ",
"   >rrr__[;8.8f_%&(jjjr_rrrr__[[y.qmmjjrr.mjjjrrrrr%y...ei88y^mjjjjjrjrj__n.n{m1jn]2>..]mmmjrr%8.jrn_.jjjrr_r_r_%[;^   ",
"   !_r__%[y.ei(.yy(jjjrrrr_r_%[^.(mjjjrr_.ejjrrrrr__[n.ejjj[8.jjjjjrrrr__&.{2mmjrfws.8>mmmjjr_y.%mjf&.jjrrrrr__%[;sc   ",
"    >__[[^.(mjj_&..rjjrr_rr_[[f.(mmjjrr__n;jrrr___[[n.;mjjr_%.;jjjrrr___&.w2mjjrr_..q22mjjj__;.&jjjry.;jjrr___%[;s(    ",
"     __[f.(mmjjrrr.njrrr___%[s..mjjrrr___n;jrr__[[;8.;mjjrr__n(jjrr__[[s.wmmjjjr__n.2mmjjj__%8.mjjrrrn.;r____[;fqc<    ",
"     >[f..jjjjjr_r;.;jr__[[[s.8rjjjrrr___n(jr__[;fn.ejjjjrr_%&.jjr__[;s.8mmjjrr___&.imjjr_%%y.imjjrr__n.;__%[[sw<]     ",
"      i..>jjrr_r___n8rr_[[;s88rjjjrr_r___&nr__[;s8.emjjrr____[.frr_[;s.8>mjjrr_r___.sjjr_%[s.&jjjrrr___n.s[;;(cid      ",
"       :rmjjrrrr_r_[.y_[;f&8.%mjjrrrrr___&y_[[;&8.emjjjrrrr__%nnr_[;s8.rjjrrr_r_r__n(rr_%[;8.jjjrr_r____n.^(8em{       ",
"        l>jrrrr_r___^.......emjjrrrr_rr__&.......emjjrrrrr___[&.......;jrrr________&........%jjrr____r___n.qji         ",
"          pi__r_r___[8[jjrr8imjjr_rrr_r___nfjrr_.mmjjrr_rrr___[.jmmjj[n(f[________%[n&%%_%_fy._r_________[8]           "};
