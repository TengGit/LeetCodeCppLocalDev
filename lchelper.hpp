// MIT License
//
// Copyright (c) 2023 TengGit
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _LCHELPER_HPP
#define _LCHELPER_HPP

#include <bits/stdc++.h>

namespace LC {

// ListNode
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

namespace _internal {

using namespace std;

// Input functions

bool input(int &obj) {
    return scanf("%d", &obj) == 1;
}

bool input(long long &obj) {
    return scanf("%lld", &obj) == 1;
}

bool input(string &str) {
    int c = getchar();
    while (c != EOF && isspace(c)) {
        c = getchar();
    }
    if (c == EOF || c != '\"') {
        ungetc(c, stdin);
        return false;
    }

    // found '\"', deal with the string
    str.clear();
    bool isEscape = false;
    c = getchar();
    while (c != EOF && (isEscape || c != '\"')) {
        if (isEscape) {
            switch (c) {
            case 'a': c = '\a'; break;
            case 'b': c = '\b'; break;
            case 'n': c = '\n'; break;
            case 't': c = '\t'; break;
            case 'v': c = '\v'; break;
            case '\'': c = '\''; break;
            case '\"': c = '\"'; break;
            case '\\': c = '\\'; break;
            case 'x':
                if (scanf("%x", &c) != 1) {
                    return false;
                }
                break;
            default:
                return false;
            }
            isEscape = false;
            str.push_back(c);
        } else {
            if (c == '\\') {
                isEscape = true;
            } else {
                str.push_back(c);
            }
        }
        c = getchar();
    }

    return c != EOF;
}

template<class T>
bool input(vector<T> &vec) {
    char ch;
    if (scanf(" %c", &ch) != 1 || ch != '[') {
        return false;
    }

    vec.clear();
    // deal with empty list
    if (scanf(" %c", &ch) != 1) {
        return false;
    }
    if (ch == ']') {
        return true;
    }
    ungetc(ch, stdin);

    vec.emplace_back();
    bool cond = input(vec.back()) && scanf(" %c", &ch) == 1;
    while (cond && ch == ',') {
        vec.emplace_back();
        cond = input(vec.back()) && scanf(" %c", &ch) == 1;
    }
    
    if (cond && ch == ']') {
        return true;
    }
    ungetc(ch, stdin);
    return false;
}

bool input(ListNode *& list) {
    vector<int> v;
    if (!input(v)) {
        return false;
    }
    ListNode node(0);
    node.next = nullptr;
    ListNode *result = &node;

    for (int n: v) {
        ListNode *newNode = new ListNode(n);
        result->next = newNode;
        result = newNode;
    }
    
    list = node.next;
    return true;
}

bool inputSeries() {
    return true;
}

template<class T, class... Args>
bool inputSeries(T &t, Args&... args) {
    return input(t) && inputSeries(args...);
}

// output functions

void output(bool obj, FILE *f = stdout) {
    fprintf(f, "%s", obj ? "true" : "false");
}

void output(int obj, FILE *f = stdout) {
    fprintf(f, "%d", obj);
}

void output(long long obj, FILE *f = stdout) {
    fprintf(f, "%lld", obj);
}

void output(const char *str, FILE *f = stdout) {
    // TODO: deal with special chars
    fprintf(f, "\"%s\"", str);
}

void output(const string &str, FILE *f = stdout) {
    output(str.c_str(), f);
}

template <class T>
void output(const vector<T> &vec, FILE *f = stdout) {
    putc('[', f);
    for (auto first = vec.begin(), last = vec.end(), it = first; it != last; ++it) {
        if (it != first) {
            fprintf(f, ", ");
        }
        output(*it, f);
    }
    putc(']', f);
}

void output(ListNode *list, FILE *f = stdout) {
    vector<int> v;
    while (list) {
        v.push_back(list->val);
        list = list->next;
    }
    output(v, f);
}

// used by RunCode
void outputSeries(FILE *) {}

template <class T, class... Args>
void outputSeries(FILE *f, const T& t, const Args& ...args) {
    output(t, f);
    outputSeries(f, args...);
}

template <class T>
struct Formatter: public tuple<const char *, T> {
    Formatter(const char *s, T v): tuple<const char *, T>(s, v) {}
};

template <class T>
Formatter<T> formatter(const char *fmt, T val) {
    return Formatter<T>(fmt, val);
}

Formatter<const char *> msg(const char *s) {
    return Formatter<const char *>("%s", s);
}

template <class T>
void output(const Formatter<T> &fmt, FILE *f) {
    fprintf(f, get<0>(fmt), get<1>(fmt));
}

#define COLOR_RED    "\033[31m"
#define COLOR_GREEN  "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_END    "\033[0m"

// output the result
template<class T>
double outputResult(const T& val, int caseNum, std::chrono::high_resolution_clock::time_point startTime) {
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = endTime - startTime;
    outputSeries(stderr,
        msg("Case" COLOR_GREEN),
        formatter("%2d", caseNum),
        msg(COLOR_END ": " COLOR_YELLOW),
        formatter("%2.6f", diff.count()),
        msg(COLOR_END " s, result: "),
        val, msg("\n")
    );
    return diff.count();
}

// RunCode
template <class Solution, class RetVal, class... Args>
void RunCode(RetVal (Solution::*func)(Args...), typename std::remove_reference<Args>::type... args) {
    Solution solution;
    int caseNum = 1;
    double totalTime = 0;
    while (inputSeries(args...)) {
        auto startTime = std::chrono::high_resolution_clock::now();
        totalTime += outputResult((solution.*func)(args...), caseNum, startTime);
        ++caseNum;
    }
    outputSeries(stderr,
        msg("Total time cost: " COLOR_YELLOW),
        formatter("%2.6f", totalTime),
        msg(COLOR_END " s.\n")
    );
}

}

template <class Solution, class RetVal, class... Args>
void RunCode(RetVal (Solution::*func)(Args...)) {
    _internal::RunCode<Solution, RetVal, Args...>(func, typename std::remove_reference<Args>::type()...);
}

}

#endif
