// 03_Recomanded_ID.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1단계 대문자 -> 소문자로 변경
void ChangeToLower_1(string &strInput)
{
    for (string::iterator iter = strInput.begin(); iter != strInput.end(); ++iter)
    {
        if (*iter >= 'A' && *iter < 'Z')
        {
            *iter += 32;
        }
    }
}

// 2단계 스페셜 문자 제거
void DeleteSpecialChar(string& strInput)
{
    string strTemp;
    for (string::iterator iter = strInput.begin(); iter != strInput.end(); ++iter)
    {  
        // 소문자 알파벳 
        if (*iter >= 'a' && *iter <= 'z')
            strTemp.push_back(*iter);

        // 숫자
        else if (*iter >= '0' && *iter <= '9')
            strTemp.push_back(*iter);

        // 그 외 특수 문자
        else if ( (*iter == '-') || (*iter == '_') || (*iter == '.'))
            strTemp.push_back(*iter);
    }

    strInput = strTemp;
}

// 3단계 연속된 .. -> .으로 치환
void InspectDots(string& strInput)
{
    string strTemp;
    int nDotCount = 0;

    for (string::iterator iter = strInput.begin(); iter != strInput.end(); ++iter)
    {
        if (*iter == '.')
        {
            if (nDotCount == 0)
            {
                nDotCount++;
                strTemp.push_back(*iter);
            }

            else
            {
                continue;
            }
        }
        
        else
        {
            strTemp.push_back(*iter);
            nDotCount = 0;
        }
    }

    strInput = strTemp;
}

// 4단계 마침표 .이 처음이나 끝에 위치한다면 제거
void FirstLastDotRemove(string& strInput)
{
    string strTemp;
    int nLength = strInput.length() - 1;

    for (string::iterator iter = strInput.begin(); iter != strInput.end(); ++iter)
    {
        if ((iter == strInput.begin()) && (*iter == '.'))
            continue;

        else if ((iter + 1) == (strInput.end()) && (*iter == '.'))
            continue;

        else
            strTemp.push_back(*iter);
    }

    strInput = strTemp;
}

// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입
void ChangeSpace2a(string& strInput)
{
    if (strInput.length() == 0)
        strInput.push_back('a');
}

// 6단계 new_id의 길이가 16글자 이상이면, 15개 문자를 제외한 나머지 문자 제거.
// 그 후 마침표가(.)가 new_id 끝에 위치한다면 끝에 있는 마침표 제거
void limit16chars(string& strInput)
{
    string strTemp;
    if (strInput.length() >= 16)
    {
        while (strInput.length() >= 16)
        {
            strInput.pop_back();
        }
    }
    
    // 끝 .제거
    char chTest = strInput.at(strInput.length() - 1);
    if (chTest == '.')
        strInput.pop_back();
}

// 7단계 new_id의 길이가 2자 이하라면, 끝 문자를 반복하여 끝에 붙입니다.
void limit3chars(string& strInput)
{
    if (strInput.length() <= 2)
    {
        while (strInput.length() <= 2)
        {
            char chFinal = strInput.at(strInput.length() - 1);
            strInput.push_back(chFinal);
        }
    }
}


string solution(string &new_id) {

    if (new_id.length() > 0)
    {
        string answer(new_id);

        // 1단계 대문자 -> 소문자
        ChangeToLower_1(answer);

        // 2단계 특수문자 제거
        DeleteSpecialChar(answer);

        // 3단계 연속된 . 하나로 치환
        InspectDots(answer);

        // 4단계 맨처음, 마지막 . 검사
        FirstLastDotRemove(answer);

        // 5단계 빈 문자열에 "a"를 대입
        ChangeSpace2a(answer);

        // 6단계 16글자 제한 후 . 제거
        limit16chars(answer);

        // 7단계 
        limit3chars(answer);

        return answer;
    }
   
    else
    {
        return "";
    }
}

int main()
{
    string strName("123_.def");
    cout << "입력 : " << strName << endl;

    string answer;
    answer = solution(strName);

    cout << "출력 : " << answer << endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
