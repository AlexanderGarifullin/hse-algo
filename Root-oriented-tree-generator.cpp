#include <bits/stdc++.h>
#define en '\n'


using namespace std;


using vi = vector<int>;


int main() {

    while (true) {
        // Генератор случайных чисел.
        mt19937 rnd(time(nullptr));

        // Ввод числа вершин.
        unsigned int n = 0;
        do {
            cout << "Enter the number of vertices in the tree:" << en;
            cin >> n;
        } while (n <= 0);
        unsigned int cntVertices = n;
        // Вершины от 1 до n.
        vi prev(n + 1);
        // Одна вершина - корень. Ее номер = 1.
        n--;
        // Номер последней отработанной вершины.
        int posLastVert = 1;
        // Обрабатываемые вершины.
        queue<unsigned int> vertices;
        vertices.push(1);
        // Номер последней отработанной вершины.
        unsigned int id = 1;

        while (n) {
            // Берем обрабатываемую вершину.
            posLastVert = vertices.front();
            vertices.pop();
            unsigned int cntChilds = 0;
            // Генерируем число детей у текущей вершины (>0);
            do {
                cntChilds = rnd() % (n + 1);
            } while (!cntChilds);
            n -= cntChilds;
            // Последняя обработанная вершина.
            unsigned int last_id = id;
            // Проходим по детям текущей вершины.
            for (unsigned int currVert = last_id + 1; currVert <= min(cntVertices, last_id + cntChilds); ++currVert) {
                prev[currVert] = posLastVert;
                vertices.push(currVert);
                id = currVert;
            }
        }
        cout << "Root = " << 1 << en << "Arcs:" << en;
        for (int i = 2; i <= cntVertices; ++i) {
            cout << i << " - " << prev[i] << en;
        }
    }
    return 0;
}
