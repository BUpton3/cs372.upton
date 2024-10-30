// socialGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "socialGraph.hpp"
int main()
{
    /*
    cout << "Social Graph Key" << endl;
    cout << "0 = Me (Breah)" << endl;
    cout << "1 = Shana" << endl;
    cout << "2 = Cory" << endl;
    cout << "3 = Rebecca" << endl;
    cout << "4 = Stephen King" << endl;
    cout << "5 = Endre Hules" << endl;
    cout << "6 = Sean" << endl;
    cout << "7 = Dorothy" << endl;
    cout << "9 = Tim Tebow" << endl;
    cout << "10 = Kaley Cuoco" << endl;
    cout << "11 = Kevin Wayne" << endl;
    cout << "12 = Blake" << endl;
    cout << "13 = Nate" << endl;
    cout << "14 = Joey" << endl;
    cout << "15 = Kylee" << endl;
    cout << "16 = Maggie" << endl;
    cout << "17 = Amanda" << endl;
    cout << "18 = Adam" << endl;
    cout << "19 = Megan" << endl;
    cout << "20 = Kevin Bacon" << endl;
    */
    cout << "Social Graph: " << endl;
    cout << "1. Me" << endl;
    cout << "2. Shana" << endl;
    cout << "3. Cory" << endl;
    cout << "4. Rebecca" << endl;
    cout << "5. Stephen King" << endl;
    cout << "6. Endre Hules" << endl;
    cout << "7. Sean" << endl;
    cout << "8. Dorothy" << endl;
    cout << "9. Tim Tebow" << endl;
    cout << "10. Kevin Wayne" << endl;
    cout << "11. Kaley Cuoco" << endl;
    cout << "12. Blake" << endl;
    cout << "13. Nate" << endl;
    cout << "14. Joey" << endl;
    cout << "15. Kylee" << endl;
    cout << "16. Maggie" << endl;
    cout << "17. Amanda" << endl;
    cout << "18. Adam" << endl;
    cout << "19. Megan" << endl;
    cout << "20. Kevin Bacon" << endl;
    cout << "\n\n";

    socialGraph<string> kevinGraph(21);
    kevinGraph.addEdge(1, 2);
    kevinGraph.addEdge(1, 3);
    kevinGraph.addEdge( 3 ,  2 );
    kevinGraph.addEdge( 1 ,  4 );
    kevinGraph.addEdge( 4 ,  5 );
    kevinGraph.addEdge( 5 ,  6 );
    kevinGraph.addEdge( 6 ,  20 );
    kevinGraph.addEdge( 3 ,  7 );
    kevinGraph.addEdge( 3 ,  8 );
    kevinGraph.addEdge( 1 ,  8 );
    kevinGraph.addEdge( 8 ,  4 );
    kevinGraph.addEdge( 1 ,  9 );
    kevinGraph.addEdge( 4 ,  9 );
    kevinGraph.addEdge( 9 ,  10 );
    kevinGraph.addEdge( 10 ,  11 );
    kevinGraph.addEdge( 11 ,  20 );
    kevinGraph.addEdge( 1 ,  12 );
    kevinGraph.addEdge( 14 ,  12 );
    kevinGraph.addEdge( 13 ,  12 );
    kevinGraph.addEdge( 13 ,  14 );
    kevinGraph.addEdge( 15 ,  1 );
    kevinGraph.addEdge( 15 ,  3 );
    kevinGraph.addEdge( 15 ,  2 );
    kevinGraph.addEdge( 16 ,  1 );
    kevinGraph.addEdge( 16 ,  15 );
    kevinGraph.addEdge( 16 ,  2 );
    kevinGraph.addEdge( 16 ,  4 );
    kevinGraph.addEdge(20, 11);
    kevinGraph.addEdge(20, 6);
    kevinGraph.printGraph();
}
