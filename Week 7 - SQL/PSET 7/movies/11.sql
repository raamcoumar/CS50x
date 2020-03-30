/* Write a SQL query to list the titles of the five highest rated movies (in order)
that Chadwick Boseman starred in, starting with the highest rated. */

SELECT movies.title
FROM movies
WHERE movies.id IN (
          SELECT stars.movie_id
          FROM stars
          JOIN ratings
          ON stars.movie_id = ratings.movie_id
          WHERE stars.person_id = (
	           SELECT people.id
	           FROM people
	            WHERE people.name = 'Chadwick Boseman')
          ORDER BY ratings.rating DESC
          LIMIT 5
        );
