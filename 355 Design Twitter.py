class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.follows = {}   # id -> followDict
        self.tweets = {}    # id -> tweetList
        self.timeStamp = 0

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        if not userId in self.tweets:
            self.tweets[userId] = []
        self.tweets[userId].append((self.timeStamp, tweetId))
        self.timeStamp += 1

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who 
            the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        if userId in self.follows:
            follows = self.follows[userId]
        else:
            follows = {}
        result = []
        if userId in self.tweets:
            result += self.tweets[userId]
        for followee in follows:
            if followee in self.tweets:
                result += self.tweets[followee][-10:]
        return [t[1] for t in sorted(result)[-10:][::-1]]
            

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId == followeeId:
            return
        if not followerId in self.follows:
            self.follows[followerId] = {}
        self.follows[followerId][followeeId] = True

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId == followeeId:
            return
        if followerId in self.follows and followeeId in self.follows[followerId]:
            del self.follows[followerId][followeeId]



# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
