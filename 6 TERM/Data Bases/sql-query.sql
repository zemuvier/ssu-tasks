USE[TASK]

GO
SELECT *
  FROM dbo.City AS c INNER JOIN dbo.Country AS r
  ON c.ID_Country = r.ID 
  ORDER BY c.Name

GO
SELECT *
  FROM dbo.Country AS r LEFT JOIN dbo.City AS c  
  ON c.ID_Country = r.ID 
  ORDER BY c.Name DESC

GO
SELECT *
  FROM dbo.Country AS r RIGHT JOIN dbo.City AS c
  ON c.ID_Country = r.ID 
  ORDER BY c.Name DESC
  
  
GO
SELECT *
  FROM dbo.Country AS r FULL OUTER JOIN dbo.City AS c
  ON c.ID_Country = r.ID 
  ORDER BY c.Name DESC 


GO
SELECT DISTINCT *
FROM dbo.City AS r1
    INNER JOIN dbo.City AS r2
    ON r1.ID_Country = r2.ID_Country
        AND r1.Name <> r2.Name
ORDER BY r1.ID

GO
SELECT *
  FROM dbo.Users WHERE Name LIKE '%Бубен%'
  ORDER BY Name 
  
GO
SELECT *
FROM Post
WHERE ID_Users = ANY
   (SELECT ID
	  FROM Users WHERE ID < 15)
ORDER BY ID

GO
SELECT *
FROM Post
WHERE ID_Users IN
   (SELECT ID
	  FROM Users WHERE ID < 15)
ORDER BY ID

GO
SELECT *
FROM Post
WHERE ID_Users > ALL
   (SELECT ID
	  FROM Users WHERE ID = 2)
ORDER BY ID_Users 

GO
SELECT Name, Address =
      CASE ID_Country
         WHEN 1 THEN 'ODIN'
         WHEN 2 THEN 'DVA'
         ELSE 'Ne och'
      END
FROM Users
ORDER BY Name 

GO
SELECT ID_Users, 100*(ID+ISNULL(Mark,0))
  FROM Rating
  
GO
SELECT * 
  FROM Rating
  ORDER BY CAST(Mark as char)
  
  GO
SELECT IIF(Mark IS NULL, 'Оценки нет', 'Пользователь оценен') Mark 
  FROM Rating
  
GO
SELECT UPPER(Name)
  FROM Users
 
 GO
SELECT LOWER(Name)
  FROM Users
  
 GO
SELECT STUFF([ID], 1, 1, '000')
  FROM Rating

GO
SELECT GETDATE()

GO
SELECT SYSDATETIMEOFFSET() 

GO
SELECT ID_Users, COUNT(*) 
  FROM Post 
  GROUP BY ID_Users

GO
SELECT ID_Users, COUNT(*) 
  FROM Post 
  GROUP BY ID_Users
  HAVING ID_Users = 3  