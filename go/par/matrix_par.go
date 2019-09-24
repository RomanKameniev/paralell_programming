package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

const MAX int = 1024
const RAND int64 = 100

func main() {
	fmt.Println("Go par program")
	fmt.Println("default values : \n MAX = ", MAX, " \n RAND = ", RAND)
	var a [MAX][MAX]int64
	var b [MAX][MAX]int64
	var c [MAX][MAX]int64
	for iteration := 1; iteration <= 10; iteration++ {
		fmt.Println("init a && b")

		generate(&a)
		generate(&b)
		fmt.Println("calculating")
		var stamp time.Time = calculate(&a, &b, &c)
		fmt.Println("time of ", iteration, " iteration is = ", time.Since(stamp), "\n test item of arr=> ", c[0][0])
	}
	var key int
	fmt.Println("End ")
	fmt.Scan(&key)
}

func generate(arr *[MAX][MAX]int64) {
	s := rand.NewSource(time.Now().UnixNano())
	r := rand.New(s)

	for x := 0; x < MAX; x++ {
		for y := 0; y < MAX; y++ {
			arr[x][y] = r.Int63n(RAND)
		}
	}
}
func power(a int64, b int64) int64 {
	return a * b
}

func calculate(arr1 *[MAX][MAX]int64, arr2 *[MAX][MAX]int64, arr3 *[MAX][MAX]int64) time.Time {
	start := time.Now()
	var wg sync.WaitGroup
	wg.Add(MAX)
	for i := 0; i < MAX; i++ {
		go func(i int) {
			defer wg.Done()
			for j := 0; j < MAX; j++ {
				var temp int64 = 0
				for k := 0; k < MAX; k++ {
					temp += power(arr1[i][k], arr2[k][j])
				}
				arr3[i][j] = temp
			}
		}(i)
	}
	wg.Wait()
	return start
}
