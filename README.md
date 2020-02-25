# algorithms
Some algorithms written in C++.

### K-means clustering
https://en.wikipedia.org/wiki/K-means_clustering

To use the k-means algorithm, you need to pass in a vector of Point objects and a 
vector of ints to store the id of the points you want the clusters to start at.
To store the results of the clustering, set a vector of Cluster objects equal
to the call of the function. See: k-means_clustering/main.cpp

vector\<Cluster> result = kmeans(vector\<Point> points, vector\<int> startPoints);

### Porter stemming
https://en.wikipedia.org/wiki/Stemming

http://snowball.tartarus.org/algorithms/porter/stemmer.html

To use the porter stemming algorithm, you need to pass in words stored as a vector
of strings. To store the results of the stemming, set a vector of strings equal
to the call of the function. See: porter_stemmer/main.cpp

vector\<string> stemmed = porterStem(vector\<string> words);