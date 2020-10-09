// 배열 용량이 꽉 찼으면 재할당받는다
if (size == capacity)
{
    // 용량을 M만큼 늘린 새 배열을 할당받는다
    int newCapacity = capacity + M;
    int *newArray = new int[newCapacity];
    // 기존의 자료를 복사한다
    for (int i = 0; i < size; i++)
        newArray[i] = array[i];
    // 기존 배열을 삭제하고 새 배열로 바꿔치기
    if (array)
        delete[] array;
    array = newArray;
    capacity = newCapacity;
}
// 배열의 끝에 원소 삽입
array[size++] = newValue;