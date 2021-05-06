function solution(enroll, referral, seller, amount) {
    var answer = [];
    var node = {
        parent: "",
        data: 0,
    }
    var node_ar = {};
    for (let i = 0; i < enroll.length; i++) {
        var node = {
            parent: referral[i],
            data: 0,
        }
        node_ar[enroll[i]] = node;
    }
    for (let i = 0; i < seller.length; i++) {
        let name = seller[i];
        let share = 0, remain = 0, t_amount = amount[i] * 100;
        while (1) {
            remain = Math.floor((t_amount / 10) * 1);
            share = t_amount - remain;
            node_ar[name].data += share;
            if (remain <= 0) break;
            if (node_ar[name].parent === "-") break;
            t_amount = remain;
            name = node_ar[name].parent;
        }
    }
    for (let i = 0; i < enroll.length; i++) {
        answer.push(node_ar[enroll[i]].data);
    }
    return answer;
}

solution(["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"], ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"], ["young", "john", "tod", "emily", "mary"], [12, 4, 2, 5, 10]);

