function bubbleSort(arr, n) {
    let s1 = [];

    for (let num = 0; num < arr.length; num++) s1.push(arr[num]);

    let s2 = [];

    for (let i = 0; i < n; i++) {
        // Alternatively
        if (i % 2 == 0) {
            while (s1.length != 0) {
                let t = s1.pop();

                if (s2.length == 0) s2.push(t);
                else {
                    if (s2[s2.length - 1] > t) {
                        // Swapping
                        let temp = s2.pop();
                        s2.push(t);
                        s2.push(temp);
                    } else {
                        s2.push(t);
                    }
                }
            }

            // Tricky step
            arr[n - 1 - i] = s2.pop();
        } else {
            while (s2.length != 0) {
                let t = s2.pop();

                if (s1.length == 0) s1.push(t);
                else {
                    if (s1[s1.length - 1] > t) {
                        // Swapping
                        let temp = s1.pop();

                        s1.push(t);
                        s1.push(temp);
                    } else s1.push(t);
                }
            }

            // Tricky step
            arr[n - 1 - i] = s1.pop();
        }
    }
    console.log(arr.join(" "));
}

let arr = [5, 1, 4, 2, 8];
bubbleSort(arr, arr.length);