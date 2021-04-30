function solution(user_id, banned_id) {
    var answer = 0;
    var ar = [];
    let origin = user_id.slice();
    for (let i = 0; i < (1 << 9); i++)
        ar.push(0);
    function match(id1, id2) {
        if (id1.length !== id2.length) return 0;

        for (let idx = 0; idx < id1.length; idx++) {
            if (id1[idx] === '*') continue;
            if (id1[idx] !== id2[idx]) return 0;
        }
        return 1;
    }
    function ch(user_id, banned_id, start, sum) {
        if (banned_id.length === 0) {
            ar[sum] = 1;
            return;
        }
        for (let idx = 0; idx < 1; idx++) {
            let element = banned_id[idx];
            for (let idx2 = 0; idx2 < user_id.length; idx2++) {
                if (match(element, user_id[idx2]) === 1) {
                    let temp1 = user_id.slice();
                    let temp2 = banned_id.slice();
                    temp1.splice(idx2, 1);
                    temp2.splice(idx, 1);
                    ch(temp1, temp2, idx2, (sum | (1 << origin.findIndex(e => e === user_id[idx2]))));
                }
            }
        }
    }
    ch(user_id, banned_id, 0, 0);
    answer = ar.filter(v => v === 1).length
    console.log(answer);
    return answer;
}

solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "*rodo", "******", "******"])