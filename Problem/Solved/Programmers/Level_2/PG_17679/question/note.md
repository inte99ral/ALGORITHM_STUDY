# 정리

## 과거 나의 풀이

### 풀이 과정

소문자로 바꿔서 기억하고

소문자를 소문자로 바꿔도 똑같다는 발상 하에 만들어진 알고리즘

참신은 했으나 일일히, 소문자 <-> 대문자를 해주어야하기에 불필요한 연산이 너무 많으며

웃긴 사실은 결국 소문자로 바꾸기 위해 일일히 int 메모리를 할당하면서 메모리가 오히려 많이 사용되었다.

과거의 나는 그렇게 까지 bool 매트릭스를 만들기 싫었던걸까

참신하긴 했으니 칭찬한다.

### 풀이 코드

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int m, int n, vector<string> board) {
    // 판의 높이 m , 폭 n 각 n길이당 삭제해야할 시작과 끝 입력받기
    // 65 90에 97~122 변환 후 삭제
    int answer = 0;
    int del = 1;
    vector<vector<char>> b(n, vector<char>(0));
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) b[j].insert(b[j].begin(),board[i][j]);

    while(del != 0){
        del = 0;

        //전체 돌면서 2*2 상황 체크
        for(int i = 0; i < (n - 1); i++){// 줄
            for(int j = 0; j < (m - 1); j++){ // 순위
                char m=tolower(b[i][j]),u=tolower(b[i][j+1]),r=tolower(b[i+1][j]),ur=tolower(b[i+1][j+1]);
                if((m==u) && (m==r) && (m==ur))b[i][j] = m, b[i+1][j] = m, b[i][j+1] = m, b[i+1][j+1] = m;
            }
        }

        for(int i = 0; i < n; i++){// 줄
            for(int j = 0; j < m; j++){ // 순위
                if(b[i][j] > 90){
                    b[i].erase(b[i].begin()+j);
                    b[i].push_back(63);
                    j--;
                    del++;
                }
            }
        }
        answer += del;
    }

    return answer;
}
```
