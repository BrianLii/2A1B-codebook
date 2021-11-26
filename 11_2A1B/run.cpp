rm -f a.out
g++ -std=c++11 -O2 -Wextra -Wall $1 

if [ -f "a.out" ]; then
    echo "[successfully compiled]"
    ./a.out
else 
    echo "[compile error]"
fi

