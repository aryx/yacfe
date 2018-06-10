#!!!!You need to source me with "source env.sh" from the _RIGHT_ directory!!!!
if [ ! -r data/standard.h ]
    then echo "There is no standard.h in data/. 
Are you sure you run this script from the source directory ?
";
fi

# To compile the source. 
echo setting PATH
export PATH=/home/pad/packages/bin:/home/pad/packages/sbin:$PATH
echo setting LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/home/pad/packages/lib:$LD_LIBRARY_PATH

# To run. To find the data/ files.
echo setting YACFE_HOME
export YACFE_HOME=`pwd`

