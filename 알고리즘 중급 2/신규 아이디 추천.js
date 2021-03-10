function solution(new_id){
    let answer = '';
    let idx1 = 0;
    let idx2 = 0;
    let checkNum = /[0-9]/;
    let checkEng = /[a-z]/;
    let checkSpc = /[-_.]/;
    function check_id(new_id){
        let size = new_id.length;
        if(size < 3 || size > 15)
         return false;
        for(let i = 0 ; i < size ; i++)
        {
            let ch = new_id[i];
            if(ch === '.')
            {
                if(i === 0 || i === (size - 1 ))
                    return false;
                else if (new_id[i+1] === '.')
                    return false;
            }
            else 
            {
                if(checkNum.test(ch) || checkEng.test(ch) || checkSpc.test(ch))
                    continue;
                else 
                 return false;
            }
        }
    }
    if(check_id(new_id))
        return new_id;
    new_id = new_id.toLowerCase();
    while(1)
    {
        let size = new_id.length;
        let size2 = answer.length;
        if(idx1 === size) break;
        let ch = new_id[idx1];
        if(ch === '.')
        {
            if( size2 === 0 || size2 === (size - 1) ){
                
            }
            else 
            {
                if(answer[size2 - 1] === '.')
                    {}
                else 
                 answer += ch ;          
            }
        }
        else 
        {
            if(!checkNum.test(ch) && !checkEng.test(ch) && !checkSpc.test(ch))
            {
                if(ch === ' ')
                    answer += 'a';
                else 
                    {};
            }
            else 
                answer += ch ;          
        }
        idx1++;
    }
    while(answer.length > 0 && answer[0] === '.' )
    {
        answer = answer.substr(1);
    }
    while(answer.length > 0 && answer[answer.length-1] === '.' )
    {
        answer = answer.substr(0 , answer.length-1);
    }
    if(answer.length === 0)
        answer += 'a';

    if(answer.length >= 16){
        answer = answer.substring(0 , 15)
        while(answer[answer.length-1] === '.')
        {
            answer = answer.substring(0 , answer.length-1);
        }
    }
    while(answer.length < 3)
    {
        answer += answer[answer.length-1];
    }
    return answer;
}

console.log( solution(	"abcdefghijklmn.p") );