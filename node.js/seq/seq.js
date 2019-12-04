
const MAX = 1024;
const RAND_KEY = 100;
(function main() {
    const a = [], b = [], c = [];
    console.log("Node.js seq program \n");
    console.log("default value: \n arr length= %d \n key range from 0 to %d \n ", MAX, RAND_KEY);
    for (let i = 1; i <= 10; i++) {
        console.log("init arr a && b\n");
        generateArr(a);
        generateArr(b);
        console.log("calculating arr\n");
        clean(c)
        let ijk_time = ijk(a, b, c)
        console.info(` ijk seq time of ${i} iteration is = ${ijk_time}ms \n test item of arr=>${c[0][0]}`)
        clean(c)
        let jik_time = jik(a, b, c)
        console.info(` jik seq time of ${i} iteration is = ${jik_time}ms \n test item of arr=>${c[0][0]}`)
        clean(c)
        let jki_time = jki(a, b, c)
        console.info(` jki seq time of ${i} iteration is = ${jki_time}ms \n test item of arr=>${c[0][0]}`)
        clean(c)
        let ikj_time = ikj(a, b, c)
        console.info(` ikj seq time of ${i} iteration is = ${ikj_time}ms \n test item of arr=>${c[0][0]}`)
    }

})()

function generateArr(arr) {
    for (let a = 0; a < MAX; a++) {
        arr[a] = []
        for (let b = 0; b < MAX; b++) {
            arr[a].push(Math.floor((Math.random() * RAND_KEY) + 1))
        }
    }
}

function ijk(arr1, arr2, res) {
    console.time("answer time");

    let i, j, k;
    var start = new Date()
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            for (k = 0; k < MAX; k++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    console.timeEnd("answer time");

    return new Date() - start
}
function jik(arr1, arr2, res) {
    console.time("answer time");
    
    let i = 0, j = 0, k = 0;
    var start = new Date()
    for (; j < MAX; j++) {
        for (i = 0; i < MAX; i++) {
            for (k = 0; k < MAX; k++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    console.timeEnd("answer time");

    return new Date() - start
}
function jki(arr1, arr2, res) {
    console.time("answer time");

    let i = 0, j = 0, k = 0;
    var start = new Date()
    for (; j < MAX; j++) {
        for (k = 0; k < MAX; k++) {
            for (i = 0; i < MAX; i++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    console.timeEnd("answer time");

    return new Date() - start
}

function ikj(arr1, arr2, res) {
    console.time("answer time");

    let i = 0, j = 0, k = 0;
    var start = new Date()
    for (i = 0; i < MAX; i++) {
        for (k = 0; k < MAX; k++) {
            for (j = 0; j < MAX; j++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
       console.timeEnd("answer time");

    return new Date() - start
}

function clean(c) {
    c.length = 0;
    for (let x = 0; x < MAX; x++) {
        c[x] = []
        for (let y = 0; y < MAX; y++) {
            c[x].push(0)
        }
    }
}