SELECT ROUND(AVG(ratings.rating), 2)
FROM ratings
INNER JOIN movies
ON movies.id = ratings.movie_id
WHERE movies.year = 2012;
