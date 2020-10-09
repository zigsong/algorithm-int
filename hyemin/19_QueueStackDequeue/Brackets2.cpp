#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool wellMatched(const string &formula)
{
    // 여는 괄호 문자들과 닫는 괄호 문자들
    const string opening("({["), closing(")}]");
    // 이미 열린 괄호들을 순서대로 담는 스택
    stack<char> openStack;
    for (int i = 0; i < formula.size(); ++i)
        // 여는 괄호인지 닫는 괄호인지 확인
        if (opening.find(formula[i]) != -1)
            // 여는 괄호라면 스택에 집어넣음
            openStack.push(formula[i]);

        // 여는 괄호가 아닌 경우 스택 맨 위의 문자와 맞춰보기
        // 스택이 비어 있는 경우는 실패
        else
        {
            // 다 닫혀서 없는 경우는 성공 아닌가? for문 다 돌기 전에 stack이 비었다고 해서 실패인 건 아닌데,,
            // 어차피 지금 false처리 해줘도 비어 있으면 for문 다 돌고 최종적으로는 true를 리턴할텐데 왜 굳이 false 처리를 하는가?
            // 아 openStack.pop()까지 가지 않게 하기 위한 처리! 그냥 현재 들어온 문자와 짝을 이루지 않는다는 의미의 false인듯
            if (openStack.empty())
                return false;
            // 서로 짝이 맞지 않아도 실패
            if (opening.find(openStack.top()) != closing.find(formula[i]))
                return false;
            // 짝을 맞춘 괄호는 스택에서 뺀다
            openStack.pop();
        }
    // 닫히지 않은 괄호가 없어야 성공
    return openStack.empty();
}