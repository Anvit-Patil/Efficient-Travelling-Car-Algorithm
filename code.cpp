#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    int distance;
    Node *next;
};

/*
*   Function to create and add new city in the list
*   @param          **city - pointer to a pointer containing address of first city
                    cityName - string containing name of the city
                    nextCityDistance - integer containing distance of next city from current city
*   @return         None
*/
void addCity(Node **city, string cityName, int nextCityDistance)
{
    Node *newCity = new Node(); // newCity - pointing to new node which needs to be added in the list
    Node *lastCity = *city;     // lastCity - pointing to last city in the list
    newCity->name = cityName;
    newCity->distance = nextCityDistance;
    newCity->next = NULL;

    if (*city == NULL)
    {
        *city = newCity;
        return;
    }

    while (lastCity->next != NULL)
    {
        lastCity = lastCity->next;
    }
    lastCity->next = newCity;
}

/*
*   Function to give list of cities where car need to be charged
*   @param          *city - pointer containing address of first city
                    capacity - integer containing longest disatnce covered by the car in a single charge
*   @return         None
*/
void chargingCities(Node *city, int capacity)
{
    int reminingCapacity = capacity; // remainingCapacity - remianing distance which can be covered by the car once it reaches to another city
    cout << "You need to stop and recharge your car at: " << city->name << " ";
    while (city->next != NULL)
    {
        if (reminingCapacity >= 2 * city->distance)
        {
            reminingCapacity = reminingCapacity - city->distance;
            city = city->next;
        }
        else
        {
            cout << city->name << " ";
            reminingCapacity = capacity;
        }
    }
    cout << city->name;
}

/*
 *   Main function
 *   @param          None
 *   @return         0 integer
 */
int main()
{
    // totalCities = total number of cities including source and destination
    // distance = distance of next city from the current city
    // name = name of city
    // firstCity = head which is pointing to source city
    // capacity = longest disatnce covered by the car in a single charge

    int totalCities, distance = 11, capacity;
    string name;
    Node *firstCity = NULL;
    bool flag = 0;

    // Accepting capacity of the electric car from user
    do
    {
        cout << "Please enter the capacity of the car (between 250 and 350): ";
        cin >> capacity;

    } while (capacity < 250 || capacity > 350);

    // Accepting value of total number of cities from user
    do
    {
        cout << "Please enter the number of cities (greater than 3 and less than 20): ";
        cin >> totalCities;
    } while (totalCities < 4 || totalCities > 20);

    // Accepting name and distance (distance is distance of next city from current city) of each city from user
    for (int i = 0; i < totalCities; i++)
    {
        cout << "Enter city name: ";
        cin >> name;
        do
        {
            if (flag == 0)
            {
                cout << "Enter distance between " << name << " and next city having charger (between 10 and " << capacity / 2 << " ): ";
                cin >> distance;
                if (distance < 10 || distance > capacity / 2)
                {
                    cout << "Invalid distance! Please enter again." << endl;
                }
            }
        } while (distance < 10 || distance > capacity / 2);

        if (i == totalCities - 2)
        {
            flag = 1;
        }
        // Function to create node of the city and add it in the linked list
        addCity(&firstCity, name, distance);
    }
    // Function to get the list of cities where electric car need to be charged
    chargingCities(firstCity, capacity);
    return 0;
}