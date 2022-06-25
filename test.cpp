#include "myTwitter.h"
#include <fstream>
int current_time = 1;
int max_recent_num = 5;
User UsrList[MAX_USER];

/* Initialize each User */
void init_user() {
    for (int i=0; i<MAX_USER; i++) {
        UsrList[i].self_id = i;
        UsrList[i].p_my_tweets_head = NULL;
        UsrList[i].followings_size = 0;
        for (int j=0; j<MAX_FOLLOWEE; j++)
            UsrList[i].followings[j] = NULL;
    }
}

/* 
    Task 1: Determines if the specified user has sent a tweet
    Link List: isEmpty
    Input:
        user_id: int, must smaller than MAX_USER. Used to get the User in UsrList
    Return:
        True: empty
        False: not empty
*/
bool isEmpty(int user_id) {
    if (user_id > MAX_USER)
        throw invalid_argument( "User ID is out of scope!" );
    /*******************************************
                 Your code begin at here
    *******************************************/
   if ( UsrList[user_id].p_my_tweets_head == NULL )
   {
       return true;
   }
   else
   {
       return false;
   }
    /*******************************************
                 Your code end at here
    *******************************************/
}

/* 
    Task 2: Post a tweet given a user 
    Link List : Insert 
    Input:
        user_id: int, must smaller than MAX_USER. Used to get the User in UsrList
    Return:
        None
*/
void postTweet(int user_id) {
    if (user_id > MAX_USER)
        throw invalid_argument( "User ID is out of scope!" );
    /* Initialize new Tweet */
    Tweet *p_NewTweet = new Tweet();
    p_NewTweet->timestamp = current_time;
    p_NewTweet->tweet_id = MAX_TWEETS*user_id + current_time;
    p_NewTweet->p_next_tweet = NULL;

    /*******************************************
                 Your code begin at here
    *******************************************/
   if ( isEmpty(user_id) )
   {
        p_NewTweet->p_next_tweet = NULL;
        UsrList[user_id].p_my_tweets_head = p_NewTweet ;
   }
   else 
   {
       p_NewTweet->p_next_tweet = UsrList[user_id].p_my_tweets_head;
       UsrList[user_id].p_my_tweets_head = p_NewTweet ;
   }
    /*******************************************
                 Your code end at here
    *******************************************/
    current_time++;     // Time incremented by 1 for each tweet added
}

/* 
    Task 3: 
    Retrieve the 5 most recent tweets in the user's news feed. 
    Each item in the news feed must be posted by users who the user followed or by the user herself. 
    Tweets must be ordered from most recent to least recent.

    Link List : Search & Compare
    Input:
        user_id: int, must smaller than MAX_USER. Used to get the User in UsrList
    Return:
        None
*/
void printNewsFeed(int user_id) {
    cout << "Current time is: " << current_time << endl;
    cout << "You should display recent " << max_recent_num << " tweets" << endl;

    /*******************************************
                 Your code begin at here
    *******************************************/
   int num=0;
   int id;
   int max=MAX_TWEETS;
   for (int i = 0; i < 5; i++ )
   {
       for ( Tweet* p = UsrList[user_id].p_my_tweets_head; p != NULL; p = p->p_next_tweet )
       {
           if ( (num < p->timestamp) && ( p->timestamp < max ) )
           {
               id = p->tweet_id;
               num = p->timestamp;
           }
       }
       for ( int j = 0; j <UsrList[user_id].followings_size; j++ )
       {
           for ( Tweet* p = UsrList[user_id].followings[j]->p_my_tweets_head; p != NULL; p = p->p_next_tweet )
           {
               if ( (num < p->timestamp) && ( p->timestamp < max ) )
               {
                    id = p->tweet_id;
                    num = p->timestamp;
               }   
           }
       }
       max = num;
       num = 0;
       cout << id << endl;
   }
    /*******************************************
                 Your code end at here
    *******************************************/

}

void follow(int user_id_A, int user_id_B) {
    int current_size = UsrList[user_id_A].followings_size;
    UsrList[user_id_A].followings[current_size] = &UsrList[user_id_B];
    UsrList[user_id_A].followings_size++;
}

void printTweets(int user_id) {
    Tweet *p = UsrList[user_id].p_my_tweets_head;
    if (isEmpty(user_id)) {
        cout << "Tweet of user " << user_id << " is empty. " << endl;
        return;
    }
    cout << "Tweets of user " << user_id << ": ";
    if (user_id == 0)
        while (p != NULL) {
            cout << p->tweet_id << " ";
            p = p->p_next_tweet;
        }
    else
        while (p != NULL) {
            cout << p->tweet_id << " ";
            p = p->p_next_tweet;
        }
    cout << endl;
}
int main() {
    /* Initialize my Twitter */
    init_user();

    /* Add relationships based on following_relationship.txt */
    char buffer[256];
    ifstream following("following_relationship.txt");
    if (!following.is_open())
        throw invalid_argument( "Cannot find following_relationship.txt, please check your current path!" );
    while (!following.eof()) {
        following.getline(buffer, 100);
        follow(int(buffer[0] - '0'), int(buffer[2] - '0'));
    }

    /* Post tweets based on tweet.txt */
    ifstream tweets("tweet.txt");
    if (!tweets.is_open())
        throw invalid_argument( "Cannot find tweet.txt, please check your current path!" );
    while (!tweets.eof()) {
        tweets.getline(buffer, 100);
        postTweet(int(buffer[0] - '0'));
    }

    /* Check Task 1 and Task 2 */
    cout << "******************************************" << endl;
    cout << "All tweets in current myTwitter: " << endl;
    cout << "******************************************" << endl;
    for (int user_id=0; user_id<MAX_USER; user_id++)
        printTweets(user_id);

    // /* Check Task 3 */
    // cout << "******************************************" << endl;
    // cout << "Please input tweet_id and user id you want to delete. " << endl;
    // int tweet_id, user_id;
    // cin >> tweet_id >> user_id;
    // cout << "User " << user_id << " deletes " << tweet_id << endl;
    // delTweet(tweet_id, user_id);
    // cout << "All tweets in current myTwitter: " << endl;
    // cout << "******************************************" << endl;
    // for (int user_id=0; user_id<MAX_USER; user_id++)
    //     printTweets(user_id);

    /* Check Task 4 */
    cout << "******************************************" << endl;
    cout << "Recent news feed of user 1: " << endl;
    cout << "******************************************" << endl;
    printNewsFeed(1);
}