
class Heap {
    constructor() {
        this.heap = [];
    }
    swap(a, b) {
        [this.heap[a], this.heap[b]] = [this.heap[b] , this.heap[a]]
    }
    size() {
        return this.heap.length
    }
    insert(value) {
        let idx, parent = 0
        this.heap.push(value)
        idx = this.heap.length-1
        if(idx === 0)
            parent = 0;
        else if(idx % 2=== 0)
            parent = Math.floor((idx-1)/2)
        else 
            parent = Math.floor(idx / 2)

        while(this.heap[parent].diff > value.diff) {
            this.swap(idx, parent)
            idx = parent
            if(idx === 0)
                parent = 0;
            else if(idx % 2=== 0)
                parent = Math.floor((idx-1)/2)
            else 
                parent = Math.floor(idx / 2)
        }

    }
    delete() {
        // 힙의 pop은 루트요소를 제거하고 맨 끝 요소를 위로 올림
        let value = this.heap.shift();
        let [idx, lastIdx] = [0, this.heap.length-1]

        while(idx < lastIdx) {
            // 1. 자식요소가 없는경우, 2. 왼쪽자식만 있는경우 , 3. 왼쪽오른쪽 다있는 경우
              
            let [leftChildIdx, rightChildIdx] = [idx*2+1, idx*2+2]
            if(lastIdx < leftChildIdx) {
                break
            } else if(lastIdx < rightChildIdx) {
                if(this.heap[idx].diff > this.heap[leftChildIdx].diff) {
                    this.swap(idx, leftChildIdx)
                    idx = leftChildIdx
                } else {
                    break
                }
            } else {
                if(this.heap[idx].diff > this.heap[leftChildIdx].diff && this.heap[idx].diff > this.heap[rightChildIdx].diff) {
                    if(this.heap[leftChildIdx].diff < this.heap[rightChildIdx].diff) {
                        this.swap(idx, leftChildIdx)
                        idx = leftChildIdx
                    } else {
                        this.swap(idx, rightChildIdx)
                        idx = rightChildIdx
                    }
                } else if(this.heap[idx].diff > this.heap[leftChildIdx].diff) {
                    this.swap(idx, leftChildIdx)
                    idx = leftChildIdx
                } else if(this.heap[idx].diff > this.heap[rightChildIdx].diff) {
                    this.swap(idx, rightChildIdx)
                    idx = rightChildIdx
                } else {
                    break
                }
            }
        }
        return value
    }
}
function solution(land, height) {
    let size = land[0].length;
    let dx = [-1 , 0 ,1, 0]
    let dy = [0 , 1, 0 , -1]
    let answer = 0;
    let visit = Array.from(Array(301) , ()=>Array(301).fill(0));
    let obj = {x : 0 , y : 0 ,diff : 0};
    let lists = new Heap();
    lists.insert(obj);
    visit[0][0] = 1;

    while(1)
    {
        if(!lists.size()) break;
        let obj = lists.delete();
        if(visit[obj.x][obj.y] === 0){
            visit[obj.x][obj.y] = 1;
            answer += obj.diff;
        }
        for(let i = 0 ; i < 4 ;i++)
        {
            let nx = obj.x + dx[i];
            let ny = obj.y + dy[i];
            if(nx < 0 || nx >= size || ny < 0 || ny >= size || visit[nx][ny] === 1)
                continue;
            let _diff = Math.abs(land[obj.x][obj.y] - land[nx][ny]);
            if( _diff <= height) _diff = 0;
            lists.insert( { x : nx , y : ny , diff : _diff});
        }
    }
    
    return answer;
}

console.log(solution([[1, 4, 8, 10], [5, 5, 5, 5], [10, 10, 10, 10], [10, 10, 10, 20]], 3));