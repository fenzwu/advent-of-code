import * as fs from 'fs';

function isDigit(character: string): boolean {
    const code = character.charCodeAt(0);
    return !isNaN(code) && code >= 48 && code <= 57;
}

function part1(lines: string[]): number {
    let res = 0;
    for (const line of lines) {
        let l = 0, r = line.length - 1;
        let digit = '';
        while (l <= r) {
            if (isDigit(line[l])) {
                digit += line[l];
                break;
            }
            l++;
        }

        while (r >= 0) {
            if (isDigit(line[r])) {
                digit += line[r];
                break;
            }
            r--;
        }

        if (digit !== '') {
            res += parseInt(digit);
        }
    }
    return res;
}

function part2(lines: string[]): number {
    const numMap: { [key: string]: number } = {
        'one': 1,
        'two': 2,
        'three': 3,
        'four': 4,
        'five': 5,
        'six': 6,
        'seven': 7,
        'eight': 8,
        'nine': 9
    };

    let res = 0;
    for (const line of lines) {
        const n = line.length;
        const nums: number[] = [];

        for (let i = 0; i < n; i++) {
            if (isDigit(line[i])) {
                nums.push(parseInt(line[i]));
            } else {
                if (i + 2 < n) {
                    const substr = line.substring(i, i + 3);
                    if (numMap.hasOwnProperty(substr)) {
                        nums.push(numMap[substr]);
                    }
                }
                
                if (i + 3 < n) {
                    const substr = line.substring(i, i + 4);
                    if (numMap.hasOwnProperty(substr)) {
                        nums.push(numMap[substr]);
                    }
                }

                if (i + 4 < n) {
                    const substr = line.substring(i, i + 5);
                    if (numMap.hasOwnProperty(substr)) {
                        nums.push(numMap[substr]);
                    }
                }
            }
        }

        res += nums[0] * 10 + nums[nums.length - 1];
    }
    return res;
}

fs.readFile('input.txt', 'utf8', (err, data) => {
    if (err) {
        console.error('Error reading file:', err);
        return;
    }
    const lines = data.trim().split('\n');
    console.log(part1(lines));
    console.log(part2(lines));
});