/* Write a SQL query to list the names of all people who have directed a movie
hat received a rating of at least 9.0. */

SELECT people.name
FROM people
WHERE people.id IN
  (
	SELECT directors.person_id
	FROM directors
	WHERE directors.movie_id IN
		(
    SELECT movies.id
		FROM movies
		JOIN ratings
		ON movies.id = ratings.movie_id
		WHERE ratings.rating >= 9.0
    )
  );
