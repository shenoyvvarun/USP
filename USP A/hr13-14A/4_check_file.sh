# check whether the name is an entry in the directory
#ls $1 # required for the first two ways of execution
#if test $? -eq 0
#if [ $? -eq 0 ]
if ls $1
then
	echo "exists"
else
	echo "does not exist"
fi
