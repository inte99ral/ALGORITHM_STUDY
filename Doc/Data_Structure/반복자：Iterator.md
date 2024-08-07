# 반복자：Iterator

Iterator, 반복자

반복자는 요소들의 위치와 연관된 동작을 하는 객체입니다.

포인터와 개념이 흡사합니다. 컨테이너에서 어떤 요소의 위치를 나타냅니다.

​

- 연산자 : 포인터와 동일하게 참조연산이 가능합니다.

++,-- 연산자 : 가리키는 요소 주변 요소로 증감연산이 가능합니다.

==, != 연산자 : 반복자가 같은 위치를 가르키는지 비교가 가능합니다.

= 연산자 : 반복자간의 대입연산이 가능합니다.

​

이런 반복자가 있는 이유는 컨테이너와 알고리즘이 하나로 동작하게 묶어주기 때문입니다.

알고리즘은 추후에 배우겠지만, 컨테이너의 요소들을 가지고 각종 연산을 하기 때문에

반복자가 없다면 특정 컨테이너에만 종속적이게 될 수 있습니다.

반복자를 이용해서 모든 컨테이너에 결합하여 동작할 수 있도록 해주는 것입니다.

​

모든 컨테이너 클래스들은 자신의 요소를 검색하기 위해 반복자와 함수를 제공하고 있습니다.

중요한 함수는 시작과 끝을 알려주는 함수입니다.
