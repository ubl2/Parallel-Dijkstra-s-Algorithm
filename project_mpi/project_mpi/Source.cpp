#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include<iostream>
#include <vector>
#include <fstream>
#include<string>
#include <chrono>
using namespace std::chrono;
using namespace std;
#define INFINITY_1 100
string source;

string sources[10] = { "Doha", "New York", "Dubai", "London", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Houston", "Mumbai" };
string destinations[10] = { "Doha", "New York", "Dubai", "London", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Houston", "Mumbai" };
int matrix[10][10] = {
    {0, 16, 5, 12, 100, 7, 5, 19, 100, 4},
    {16, 0, 13, 100, 13, 14, 100, 5, 3, 15},
    {2, 13, 0, 16, 14, 5, 4, 17, 14, 5},
    {12, 100, 16, 0, 7, 11, 13, 13, 100, 12},
    {100, 13, 14, 7, 0, 100, 14, 14, 12, 11},
    {7, 14, 5, 11, 100, 0, 7, 16, 15, 4},
    {5, 100, 4, 100, 14, 7, 0, 21, 18, 2},
    {19, 5, 17, 13, 14, 16, 21, 0, 100, 18},
    {100, 3, 14, 100, 12, 15, 18, 100, 0, 16},
    {4, 15, 5, 12, 11, 4, 2, 18, 16, 0}
};

string sources2[10] = { "New York", "Doha", "Dubai", "London", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Houston", "Mumbai" };
string destinations2[10] = { "New York", "Doha", "Dubai", "London", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Houston", "Mumbai" };
int matrix2[10][10] = {
    {0, 16, 13, 100, 13, 14, 100, 5, 3, 15},
    {16, 0, 5, 12, 100, 7, 5, 19, 100, 4},
    {13, 2, 0, 16, 14, 5, 4, 17, 14, 5},
    {100, 12, 16, 0, 7, 11, 13, 13, 100, 12},
    {13, 100, 14, 7, 0, 100, 14, 14, 12, 11},
    {14, 7, 5, 11, 100, 0, 7, 16, 15, 4},
    {100, 5, 4, 100, 14, 7, 0, 21, 18, 2},
    {5, 19, 17, 13, 14, 16, 21, 0, 100, 18},
    {3, 100, 14, 100, 12, 15, 18, 100, 0, 16},
    {15, 1, 5, 12, 11, 4, 2, 18, 16, 0}
};

string sources3[10] = { "Dubai", "New York", "Doha", "London", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Houston", "Mumbai" };
string destinations3[10] = { "Dubai", "New York", "Doha", "London", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Houston", "Mumbai" };
int matrix3[10][10] = {
    {0, 2, 13, 16, 14, 5, 4, 17, 14, 5},
    {16, 0, 13, 100, 13, 14, 100, 5, 3, 15},
    {5, 16, 0, 12, 100, 7, 5, 19, 100, 4},
    {16, 100, 12, 0, 7, 11, 13, 13, 100, 12},
    {14, 13, 100, 7, 0, 100, 14, 14, 12, 11},
    {5, 14, 7, 11, 100, 0, 7, 16, 15, 4},
    {4, 100, 5, 100, 14, 7, 0, 21, 18, 2},
    {17, 5, 19, 13, 14, 16, 21, 0, 100, 18},
    {14, 3, 100, 100, 12, 15, 18, 100, 0, 16},
    {5, 15, 4, 12, 11, 4, 2, 18, 16, 0}
};

string sources4[10] = { "London", "New York", "Dubai", "Doha", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Houston", "Mumbai" };
string destinations4[10] = { "London", "New York", "Dubai", "Doha", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Houston", "Mumbai" };
int matrix4[10][10] = {
    {0, 100, 16, 12, 7, 11, 13, 13, 100, 12},
    {100, 0, 13, 16, 13, 14, 100, 5, 3, 15},
    {16, 13, 0, 2, 14, 5, 4, 17, 14, 5},
    {12, 16, 5, 0, 100, 7, 5, 19, 100, 4},
    {7, 13, 14, 100, 0, 100, 14, 14, 12, 11},
    {11, 14, 5, 7, 100, 0, 7, 16, 15, 4},
    {100, 100, 4, 5, 14, 7, 0, 21, 18, 2},
    {13, 5, 17, 19, 14, 16, 21, 0, 100, 18},
    {100, 3, 14, 100, 12, 15, 18, 100, 0, 16},
    {12, 15, 5, 4, 11, 4, 2, 18, 16, 0}
};

string sources5[10] = { "Madrid", "New York", "Dubai", "London", "Doha", "Istanbul", "Karachi", "Los Angeles", "Houston", "Mumbai" };
string destinations5[10] = { "Madrid", "New York", "Dubai", "London", "Doha", "Istanbul", "Karachi", "Los Angeles", "Houston", "Mumbai" };
int matrix5[10][10] = {
    {0, 13, 14, 7, 100, 100, 14, 14, 12, 11},
    {13, 0, 13, 100, 16, 14, 100, 5, 3, 15},
    {14, 13, 0, 16, 2, 5, 4, 17, 14, 5},
    {7, 100, 16, 0, 12, 11, 13, 13, 100, 12},
    {100, 16, 5, 12, 0, 7, 5, 19, 100, 4},
    {100, 14, 5, 11, 7, 0, 7, 16, 15, 4},
    {14, 100, 4, 100, 5, 7, 0, 21, 18, 2},
    {14, 5, 17, 13, 19, 16, 21, 0, 100, 18},
    {12, 3, 14, 100, 100, 15, 18, 100, 0, 16},
    {11, 15, 5, 12, 4, 4, 2, 18, 16, 0}
};

string sources6[10] = { "Istanbul", "New York", "Dubai", "London", "Madrid", "Doha", "Karachi", "Los Angeles", "Houston", "Mumbai" };
string destinations6[10] = { "Istanbul", "New York", "Dubai", "London", "Madrid", "Doha", "Karachi", "Los Angeles", "Houston", "Mumbai" };
int matrix6[10][10] = {
    {0, 14, 5, 11, 100, 7, 7, 16, 15, 4},
    {14, 0, 13, 100, 13, 16, 100, 5, 3, 15},
    {5, 13, 0, 16, 14, 2, 4, 17, 14, 5},
    {11, 100, 16, 0, 7, 12, 13, 13, 100, 12},
    {100, 13, 14, 7, 0, 100, 14, 14, 12, 11},
    {7, 16, 5, 12, 100, 0, 5, 19, 100, 4},
    {7, 100, 4, 100, 14, 5, 0, 21, 18, 2},
    {16, 5, 17, 13, 14, 19, 21, 0, 100, 18},
    {15, 3, 14, 100, 12, 100, 18, 100, 0, 16},
    {4, 15, 5, 12, 11, 4, 2, 18, 16, 0}
};

string sources7[10] = { "Karachi", "New York", "Dubai", "London", "Madrid", "Istanbul", "Doha", "Los Angeles", "Houston", "Mumbai" };
string destinations7[10] = { "Karachi", "New York", "Dubai", "London", "Madrid", "Istanbul", "Doha", "Los Angeles", "Houston", "Mumbai" };
int matrix7[10][10] = {
    {0, 100, 4, 100, 14, 7, 5, 21, 18, 2},
    {100, 0, 13, 100, 13, 14, 16, 5, 3, 15},
    {4, 13, 0, 16, 14, 5, 2, 17, 14, 5},
    {13, 100, 16, 0, 7, 11, 12, 13, 100, 12},
    {14, 13, 14, 7, 0, 100, 100, 14, 12, 11},
    {7, 14, 5, 11, 100, 0, 7, 16, 15, 4},
    {5, 16, 5, 12, 100, 7, 0, 19, 100, 4},
    {21, 5, 17, 13, 14, 16, 19, 0, 100, 18},
    {18, 3, 14, 100, 12, 15, 100, 100, 0, 16},
    {2, 15, 5, 12, 11, 4, 4, 18, 16, 0}
};

string sources8[10] = { "Los Angeles", "New York", "Dubai", "London", "Madrid", "Istanbul", "Karachi", "Doha", "Houston", "Mumbai" };
string destinations8[10] = { "Los Angeles", "New York", "Dubai", "London", "Madrid", "Istanbul", "Karachi", "Doha", "Houston", "Mumbai" };
int matrix8[10][10] = {
    {0, 5, 17, 13, 14, 16, 21, 19, 100, 18},
    {5, 0, 13, 100, 13, 14, 100, 16, 3, 15},
    {17, 13, 0, 16, 14, 5, 4, 2, 14, 5},
    {13, 100, 16, 0, 7, 11, 13, 12, 100, 12},
    {14, 13, 14, 7, 0, 100, 14, 100, 12, 11},
    {16, 14, 5, 11, 100, 0, 7, 7, 15, 4},
    {21, 100, 4, 100, 14, 7, 0, 5, 18, 2},
    {19, 16, 5, 12, 100, 7, 5, 0, 100, 4},
    {100, 3, 14, 100, 12, 15, 18, 100, 0, 16},
    {18, 15, 5, 12, 11, 4, 2, 4, 16, 0}
};

string sources9[10] = { "Houston", "New York", "Dubai", "London", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Doha", "Mumbai" };
string destinations9[10] = { "Houston", "New York", "Dubai", "London", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Doha", "Mumbai" };
int matrix9[10][10] = {
    {0, 3, 14, 100, 12, 15, 18, 100, 100, 16},
    {3, 0, 13, 100, 13, 14, 100, 5, 16, 15},
    {14, 13, 0, 16, 14, 5, 4, 17, 2, 5},
    {100, 100, 16, 0, 7, 11, 13, 13, 12, 12},
    {12, 13, 14, 7, 0, 100, 14, 14, 100, 11},
    {15, 14, 5, 11, 100, 0, 7, 16, 7, 4},
    {18, 100, 4, 100, 14, 7, 0, 21, 5, 2},
    {100, 5, 17, 13, 14, 16, 21, 0, 19, 18},
    {100, 16, 5, 12, 100, 7, 5, 19, 0, 4},
    {16, 15, 5, 12, 11, 4, 2, 18, 4, 0}
};

string sources10[10] = { "Mumbai", "New York", "Dubai", "London", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Houston", "Doha" };
string destinations10[10] = { "Mumbai", "New York", "Dubai", "London", "Madrid", "Istanbul", "Karachi", "Los Angeles", "Houston", "Doha" };
int matrix10[10][10] = {
    {0, 15, 5, 12, 11, 4, 2, 18, 16, 4},
    {15, 0, 13, 100, 13, 14, 100, 5, 3, 16},
    {5, 13, 0, 16, 14, 5, 4, 17, 14, 2},
    {12, 100, 16, 0, 7, 11, 13, 13, 100, 12},
    {11, 13, 14, 7, 0, 100, 14, 14, 12, 100},
    {4, 14, 5, 11, 100, 0, 7, 16, 15, 7},
    {2, 100, 4, 100, 14, 7, 0, 21, 18, 5},
    {18, 5, 17, 13, 14, 16, 21, 0, 100, 19},
    {16, 3, 14, 100, 12, 15, 18, 100, 0, 100},
    {4, 16, 5, 12, 100, 7, 5, 19, 100, 0}
};


int Find_min_dist(vector<int>*loc_dist, vector<int>* loc_known, int loc_n) {
    int loc_u = -1;
    int localvertex;
    int shortest_dist = INFINITY_1;

    for (localvertex = 0; localvertex < loc_n; localvertex++) {
        if (loc_known->at(localvertex)!=1) {
            if (loc_dist->at(localvertex) < shortest_dist) {
                shortest_dist = loc_dist->at(localvertex);
                loc_u = localvertex;
            }
        }
    }
    return loc_u;
}


void Dijkstra_Init(int loc_mat[], vector<int>* loc_pred , vector<int>*loc_dist, vector<int> *loc_known,
    int my_rank, int loc_n) {
    int localvertex=0;

    if (my_rank == 0)
        loc_known->at(0) = 1;
    else
        loc_known->at(0) = 0;

    for (localvertex = 0; localvertex < loc_n; localvertex++)
        loc_known->at(localvertex) = 0;

    for (localvertex = 0; localvertex < loc_n; localvertex++) {
        loc_dist->at(localvertex) = loc_mat[localvertex];
        loc_pred->at(localvertex) = 0;
    }
}


void Dijkstra(int loc_mat[], vector<int>*loc_dist, vector<int>* loc_pred, int loc_n, int n,
    MPI_Comm comm) {

    int i;
    int loc_v = 0;
    int loc_u = 0, glbl_u = 0;
    int new_dist = 0, my_rank = 0;
    int dist_glbl_u = 0;
    int my_min[2];
    int glbl_min[2];
    vector<int> loc_known;
    MPI_Comm_rank(comm, &my_rank);
    for (int i = 0; i < loc_n; i++)
    {
        loc_known.push_back(-1);
    }

    Dijkstra_Init(loc_mat, loc_pred, loc_dist, &loc_known, my_rank, loc_n);

    //Find the minimum distance vertex.
    for (i = 0; i < n - 1; i++) {
        loc_u = Find_min_dist(loc_dist, &loc_known, loc_n);

        if (loc_u != -1) {
            my_min[0] = loc_dist->at(loc_u);
            int vertex = my_rank * loc_n;
            my_min[1] = loc_u + vertex;
        }
        else {
            my_min[0] = INFINITY_1;
            my_min[1] = -1;
        }

        //Find the global minimum distance by finding the minimum distances from each processor.
        
        MPI_Allreduce(my_min, glbl_min, 1, MPI_2INT, MPI_MINLOC, comm);

        dist_glbl_u = glbl_min[0];
        glbl_u = glbl_min[1];

        if (glbl_u == -1)
            break;
        int rank = 0;
        rank = glbl_u / loc_n;
        if (rank == my_rank) {
            loc_u = glbl_u % loc_n;
            loc_known[loc_u] = 1;
        }

        int localvertex;
        for (localvertex = 0; localvertex < loc_n; localvertex++) {
            if (loc_known[localvertex]!=1) {
                new_dist = dist_glbl_u + loc_mat[glbl_u * loc_n + localvertex];
                if (new_dist < loc_dist->at(localvertex)) {
                    loc_dist->at(localvertex) = new_dist;
                    loc_pred->at(localvertex) = glbl_u;
                }
            }
        }
    }
    //free(loc_known);
    loc_known.clear();
}

void Print_dists(int global_dist[], int n, int global_pred[]) {
    int v;
    cout << "The shortest distance from the source Doha to all the other destinations are:"<<"\n";
    for (v = 0; v < n; v++) {
        if (global_dist[v] == INFINITY_1) {
            cout << global_dist[v];
            if(source=="Doha")
                cout << destinations[v]<<" "<<"inf"<<"\n";
            else if(source=="New York")
                cout << destinations2[v] << " " << "inf" << "\n";
            else if (source == "Dubai")
                cout << destinations3[v] << " " << "inf" << "\n";
            else if (source == "London")
                cout << destinations4[v] << " " << "inf" << "\n";
            else if (source == "Madrid")
                cout << destinations5[v] << " " << "inf" << "\n";
            else if (source == "Istanbul")
                cout << destinations6[v] << " " << "inf" << "\n";
            else if (source == "Karachi")
                cout << destinations7[v] << " " << "inf" << "\n";
            else if (source == "Los Angeles")
                cout << destinations8[v] << " " << "inf" << "\n";
            else if (source == "Houston")
                cout << destinations9[v] << " " << "inf" << "\n";
            else if (source == "Mumbai")
                cout << destinations10[v] << " " << "inf" << "\n";
        }
        else
        {
            if (source == "Doha")
                cout << destinations[v] <<" "<< global_dist[v]<< "\n";
            else if (source == "New York")
                cout << destinations2[v] << " " << global_dist[v] << "\n";
            else if (source == "Dubai")
                cout << destinations3[v] << " " << global_dist[v] << "\n";
            else if (source == "London")
                cout << destinations4[v] << " " << global_dist[v] << "\n";
            else if (source == "Madrid")
                cout << destinations5[v] << " " << global_dist[v] << "\n";
            else if (source == "Istanbul")
                cout << destinations6[v] << " " << global_dist[v] << "\n";
            else if (source == "Karachi")
                cout << destinations7[v] << " " << global_dist[v] << "\n";
            else if (source == "Los Angeles")
                cout << destinations8[v] << " " << global_dist[v] << "\n";
            else if (source == "Houston")
                cout << destinations9[v] << " " << global_dist[v] << "\n";
            else if (source == "Mumbai")
                cout << destinations10[v] << " " << global_dist[v] << "\n";
        }
    }
    printf("\n");
    cout << "The paths are:"<<"\n";
    int  w, count, i;

    vector<int> path;
    for (int i = 0; i < n; i++)
    {
        path.push_back(-1);
    }

    for (v = 1; v < n; v++) {
        if (source == "Doha")
            cout << destinations[v]<< ":";
        else if (source == "New York")
            cout << destinations2[v] << ":";
        else if (source == "Dubai")
            cout << destinations3[v] << ":";
        else if (source == "London")
            cout << destinations4[v] << ":";
        else if (source == "Madrid")
            cout << destinations5[v] << ":";
        else if (source == "Istanbul")
            cout << destinations6[v] << ":";
        else if (source == "Karachi")
            cout << destinations7[v] << ":";
        else if (source == "Los Angeles")
            cout << destinations8[v] << ":";
        else if (source == "Houston")
            cout << destinations9[v] << ":";
        else if (source == "Mumbai")
            cout << destinations10[v] << ":";

        count = 0;
        w = v;
        while (w != 0) {
            path[count] = w;
            count++;
            w = global_pred[w];
        }
        if (source == "Doha")
            cout << destinations[0]<<"->";
        else if (source == "New York")
            cout << destinations2[0] << "->";
        else if (source == "Dubai")
            cout << destinations3[0] << "->";
        else if (source == "London")
            cout << destinations4[0] << "->";
        else if (source == "Madrid")
            cout << destinations5[0] << "->";
        else if (source == "Istanbul")
            cout << destinations6[0] << "->";
        else if (source == "Karachi")
            cout << destinations7[0] << "->";
        else if (source == "Los Angeles")
            cout << destinations8[0] << "->";
        else if (source == "Houston")
            cout << destinations9[0] << "->";
        else if (source == "Mumbai")
            cout << destinations10[0] << "->";

        for (i = count - 1; i >= 0; i--)
            if (i != 0)
            {
                if (source == "Doha")
                    cout << destinations[path[i]] << "->";
                else if (source == "New York")
                    cout << destinations2[path[i]] << "->";
                else if (source == "Dubai")
                    cout << destinations3[path[i]] << "->";
                else if (source == "London")
                    cout << destinations4[path[i]] << "->";
                else if (source == "Madrid")
                    cout << destinations5[path[i]] << "->";
                else if (source == "Istanbul")
                    cout << destinations6[path[i]] << "->";
                else if (source == "Karachi")
                    cout << destinations7[path[i]] << "->";
                else if (source == "Los Angeles")
                    cout << destinations8[path[i]] << "->";
                else if (source == "Houston")
                    cout << destinations9[path[i]] << "->";
                else if (source == "Mumbai")
                    cout << destinations10[path[i]] << "->";
            }
            else
            {
                if (source == "Doha")
                    cout << destinations[path[i]];
                else if (source == "New York")
                    cout << destinations2[path[i]];
                else if (source == "Dubai")
                    cout << destinations3[path[i]];
                else if (source == "London")
                    cout << destinations4[path[i]];
                else if (source == "Madrid")
                    cout << destinations5[path[i]];
                else if (source == "Istanbul")
                    cout << destinations6[path[i]];
                else if (source == "Karachi")
                    cout << destinations7[path[i]];
                else if (source == "Los Angeles")
                    cout << destinations8[path[i]];
                else if (source == "Houston")
                    cout << destinations9[path[i]];
                else if (source == "Mumbai")
                    cout << destinations10[path[i]];
            }

        cout << "\n";
        cout << "\n";

    }
    path.clear();
}


int main(int argc, char** argv) {
    int* loc_mat;
    int* global_dist = NULL;
    int *global_pred = NULL;
    int my_rank;
    int p;
    int loc_n;
    int n;
    MPI_Comm comm;
    auto start = high_resolution_clock::now();
    MPI_Init(NULL, NULL);
    comm = MPI_COMM_WORLD;
    MPI_Comm_rank(comm, &my_rank);
    MPI_Comm_size(comm, &p);
    if (my_rank == 0)
    {
        cout << "The available sources are:" << "\n";
        cout << "1. Doha" << "\n";
        cout << "2. New York" << "\n"; 
        cout << "3. Dubai" << "\n";
        cout << "4. London" << "\n";
        cout << "5. Madrid" << "\n";
        cout << "6. Istanbul" << "\n";
        cout << "7. Karachi" << "\n";
        cout << "8. Los Angeles" << "\n";
        cout << "9. Houston" << "\n";
        cout << "10. Mumbai" << "\n";
        cout << "Enter the source: ";
        //cin >> source;// = "Mumbai";
        getline(cin, source);
        n = 10;
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, comm);
    loc_n = n / p;

    vector<int> loc_dist;
    for (int i = 0; i < loc_n; i++)
    {
        loc_dist.push_back(-1);
    }
    vector<int> loc_pred;
    for (int i = 0; i < loc_n; i++)
    {
        loc_pred.push_back(-1);
    }
    loc_mat = (int*)malloc(n * loc_n * sizeof(int));

    MPI_Aint lb, extent;
    MPI_Datatype block_mpi_t;
    MPI_Datatype first_bc_mpi_t;
    MPI_Datatype blk_col_mpi_t;

    MPI_Type_contiguous(loc_n, MPI_INT, &block_mpi_t);
    MPI_Type_get_extent(block_mpi_t, &lb, &extent);
    MPI_Type_vector(n, loc_n, n, MPI_INT, &first_bc_mpi_t);
    MPI_Type_create_resized(first_bc_mpi_t, lb, extent, &blk_col_mpi_t);
    MPI_Type_commit(&blk_col_mpi_t);
    MPI_Type_free(&block_mpi_t);
    MPI_Type_free(&first_bc_mpi_t);

    if (my_rank == 0) {
        global_dist = (int*)malloc(n * sizeof(int));
        global_pred = (int*)malloc(n * sizeof(int));
    }

    int temp = n;
    int* mat = NULL;
    vector<int>mat1;
    for (int i = 0; i < n * n + 1; i++)
    {
        mat1.push_back(-1);
    }
    if (my_rank == 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(source=="Doha")
                    mat1[i * n + j]=matrix[i][j];
                else if(source=="New York")
                    mat1[i * n + j] = matrix2[i][j];
                else if (source == "Dubai")
                    mat1[i * n + j] = matrix3[i][j];
                else if (source == "London")
                    mat1[i * n + j] = matrix4[i][j];
                else if (source == "Madrid")
                    mat1[i * n + j] = matrix5[i][j];
                else if (source == "Istanbul")
                    mat1[i * n + j] = matrix6[i][j];
                else if (source == "Karachi")
                    mat1[i * n + j] = matrix7[i][j];
                else if (source == "Los Angeles")
                    mat1[i * n + j] = matrix8[i][j];
                else if (source == "Houston")
                    mat1[i * n + j] = matrix9[i][j];
                else if (source == "Mumbai")
                    mat1[i * n + j] = matrix10[i][j];
    }
   
    MPI_Scatter(mat1.data(), 1, blk_col_mpi_t, loc_mat, n * loc_n, MPI_INT, 0, comm);
    Dijkstra(loc_mat, &loc_dist, &loc_pred, loc_n, n, comm);

    /* Gather the results from Dijkstra */
    MPI_Gather(loc_dist.data(), loc_n, MPI_INT, global_dist, loc_n, MPI_INT, 0, comm);
    MPI_Gather(loc_pred.data(), loc_n, MPI_INT, global_pred, loc_n, MPI_INT, 0, comm);

    /* Print results */
    if (my_rank == 0) {
        Print_dists(global_dist, n, global_pred);
        free(global_dist);
        free(global_pred);
    }
   
    free(loc_mat);
    loc_pred.clear();
    loc_dist.clear();
    MPI_Type_free(&blk_col_mpi_t);
    MPI_Finalize();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;
    return 0;
}
