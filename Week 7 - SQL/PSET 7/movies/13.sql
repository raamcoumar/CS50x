SELECT people.name
FROM people
WHERE people.id = (
    SELECT stars.person_id
    FROM stars
    JOIN movies ON stars.movie_id = movies.id
    WHERE movies.id = (
        SELECT movies.id
        FROM movies
        JOIN stars ON stars.movie_id = movies.id
        JOIN people ON stars.person_id = people.id
        WHERE people.id = (
            SELECT id
            FROM people
            WHERE birth = 1958 AND name = "Kevin Bacon")
                    )
)
