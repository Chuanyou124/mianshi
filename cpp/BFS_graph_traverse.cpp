void Graph::BFS(int s) {
    Queue Q;
 
    /** Keeps track of explored vertices */
    bool *explored = new bool[n+1];
 
    /** Initailized all vertices as unexplored */
    for (int i = 1; i <= n; ++i)
    explored[i] = false;
 
    /** Push initial vertex to the queue */
    Q.enqueue(s);
    explored[s] = true; /** mark it as explored */
    cout << "Breadth first Search starting from vertex ";
    cout << s << " : " << endl;
 
    /** Unless the queue is empty */
    while (!Q.isEmpty()) {
        /** Pop the vertex from the queue */
        int v = Q.dequeue();
 
        /** display the explored vertices */
        cout << v << " ";
 
        /** From the explored vertex v try to explore all the
        connected vertices */
        for (int w = 1; w <= n; ++w)
 
            /** Explores the vertex w if it is connected to v
            and and if it is unexplored */
            if (isConnected(v, w) && !explored[w]) {
                /** adds the vertex w to the queue */
                Q.enqueue(w);
                /** marks the vertex w as visited */
                explored[w] = true;
            }
    }
    cout << endl;
    delete [] explored;
}
