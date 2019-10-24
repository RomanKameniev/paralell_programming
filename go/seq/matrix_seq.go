package main

import (
	"fmt"
	"math/rand"
	"time"
)

const MAX int = 1024
const RAND int64 = 100

func main() {
	fmt.Println("Go seq program")
	fmt.Println("default values : \n MAX = ", MAX, " \n RAND = ", RAND)
	var a [MAX][MAX]int64
	var b [MAX][MAX]int64
	var c [MAX][MAX]int64
	for iteration := 1; iteration <= 10; iteration++ {
		fmt.Println("init a && b")

		generate(&a)
		generate(&b)
		fmt.Println("calculating")
		var stamp_ijk time.Time = calculate_ijk(&a, &b, &c)
		fmt.Println("time of ijk", iteration, " iteration is = ", time.Since(stamp_ijk), "\n test item of arr=> ", c[0][0])
		empyarr(&c)
		var stamp_jik time.Time = calculate_jik(&a, &b, &c)
		fmt.Println("time of jik", iteration, " iteration is = ", time.Since(stamp_jik), "\n test item of arr=> ", c[0][0])
		empyarr(&c)
		var stamp_kji time.Time = calculate_kji(&a, &b, &c)
		fmt.Println("time of kji", iteration, " iteration is = ", time.Since(stamp_kji), "\n test item of arr=> ", c[0][0])
		empyarr(&c)

	}
	var key int
	fmt.Println("End ")
	fmt.Scan(&key)
}

func empyarr(arr *[MAX][MAX]int64) {
	for x := 0; x < MAX; x++ {
		for y := 0; y < MAX; y++ {
			arr[x][y] = 0
		}
	}
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

func calculate_ijk(arr1 *[MAX][MAX]int64, arr2 *[MAX][MAX]int64, arr3 *[MAX][MAX]int64) time.Time {
	start := time.Now()
	for i := 0; i < MAX; i++ {
		for j := 0; j < MAX; j++ {
			for k := 0; k < MAX; k++ {
				arr3[i][j] += power(arr1[i][k], arr2[k][j])
			}
		}
	}
	return start
}

func calculate_jik(arr1 *[MAX][MAX]int64, arr2 *[MAX][MAX]int64, arr3 *[MAX][MAX]int64) time.Time {
	start := time.Now()
	for j := 0; j < MAX; j++ {
		for i := 0; i < MAX; i++ {
			for k := 0; k < MAX; k++ {
				arr3[i][j] += power(arr1[i][k], arr2[k][j])
			}
		}
	}
	return start
}

func calculate_kji(arr1 *[MAX][MAX]int64, arr2 *[MAX][MAX]int64, arr3 *[MAX][MAX]int64) time.Time {
	start := time.Now()
	for k := 0; k < MAX; k++ {
		for j := 0; j < MAX; j++ {
			for i := 0; i < MAX; i++ {
				arr3[i][j] += power(arr1[i][k], arr2[k][j])
			}
		}
	}
	return start
}
