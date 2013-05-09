echo "compiling ${1}.c..."
gcc -c ${1}.c
echo "linking ${1}.o ..."
gcc ${1}.o -o ${1}
echo "running ${1} ..."
./${1}



