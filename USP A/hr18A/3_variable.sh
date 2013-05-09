# variable of a shell is local to it
# exported variable is available to the child shell
#	by value
# change to the exported variable does not affect the parent

echo "a : $a"
b=banana
echo "b : $b"
echo "path : $PATH"

# normal variables and environmental variables
# environmental variables are available to the child process

echo "c : $c"
c=coffee
echo "c : $c"



