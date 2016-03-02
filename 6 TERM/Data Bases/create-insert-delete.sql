USE [TASK]
GO

CREATE TABLE [Users] (
	ID int NOT NULL IDENTITY,
	Name varchar(100) NOT NULL,
	Date date NOT NULL,
	Address varchar(100) NOT NULL,
	ID_Country int NOT NULL,
	ID_City int NOT NULL,
	Link varchar(50) NOT NULL,
	Email varchar(50) NOT NULL,
  CONSTRAINT [PK_USERS] PRIMARY KEY CLUSTERED
  (
  [ID] ASC
  ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Themes] (
	ID int NOT NULL IDENTITY,
	Name varchar(255) NOT NULL,
	Description text NOT NULL,
  CONSTRAINT [PK_THEMES] PRIMARY KEY
  (
  [ID] ASC
  ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Tags for search] (
	ID int NOT NULL IDENTITY,
	Name varchar(255) NOT NULL,
	ID_Post int NOT NULL,
  CONSTRAINT [PK_TAGS FOR SEARCH] PRIMARY KEY
  (
  [ID] ASC
  ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Comments] (
	ID int NOT NULL IDENTITY,
	ID_User int NOT NULL,
	Date datetime NOT NULL,
	Comment text NOT NULL,
  CONSTRAINT [PK_COMMENTS] PRIMARY KEY
  (
  [ID] ASC
  ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Followers] (
	ID int NOT NULL IDENTITY,
	ID_User int NOT NULL,
	ID_Followers int NOT NULL,
  CONSTRAINT [PK_FOLLOWERS] PRIMARY KEY
  (
  [ID] ASC
  ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Post] (
	ID int NOT NULL IDENTITY,
	ID_Users int NOT NULL,
	ID_Themes int NOT NULL,
	Name varchar(100) NOT NULL,
	Description text NOT NULL,
	Data datetime NOT NULL,
  CONSTRAINT [PK_POST] PRIMARY KEY
  (
  [ID] ASC
  ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [City] (
	ID int NOT NULL IDENTITY,
	Name varchar(100) NOT NULL,
	ID_Country int NOT NULL,
  CONSTRAINT [PK_CITY] PRIMARY KEY
  (
  [ID] ASC
  ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Country] (
	ID int NOT NULL IDENTITY,
	Name varchar(100) NOT NULL,
  CONSTRAINT [PK_COUNTRY] PRIMARY KEY
  (
  [ID] ASC
  ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Rating] (
	ID int NOT NULL IDENTITY,
	ID_Users int NOT NULL,
	ID_FromWho int NOT NULL,
	Mark int NOT NULL,
  CONSTRAINT [PK_RATING] PRIMARY KEY
  (
  [ID] ASC
  ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Likes] (
	ID int NOT NULL IDENTITY,
	ID_Users int NOT NULL,
	ID_FromWho int NOT NULL,
	ID_Post int NOT NULL,
  CONSTRAINT [PK_LIKES] PRIMARY KEY
  (
  [ID] ASC
  ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
ALTER TABLE [Users] WITH CHECK ADD CONSTRAINT [Users_fk0] FOREIGN KEY ([ID_Country]) REFERENCES [Country]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Users] CHECK CONSTRAINT [Users_fk0]
GO
ALTER TABLE [Users] WITH CHECK ADD CONSTRAINT [Users_fk1] FOREIGN KEY ([ID_City]) REFERENCES [City]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Users] CHECK CONSTRAINT [Users_fk1]
GO


ALTER TABLE [Tags for search] WITH CHECK ADD CONSTRAINT [Tags for search_fk0] FOREIGN KEY ([ID_Post]) REFERENCES [Post]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Tags for search] CHECK CONSTRAINT [Tags for search_fk0]
GO

ALTER TABLE [Comments] WITH CHECK ADD CONSTRAINT [Comments_fk0] FOREIGN KEY ([ID_User]) REFERENCES [Users]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Comments] CHECK CONSTRAINT [Comments_fk0]
GO

ALTER TABLE [Followers] WITH CHECK ADD CONSTRAINT [Followers_fk0] FOREIGN KEY ([ID_User]) REFERENCES [Users]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Followers] CHECK CONSTRAINT [Followers_fk0]
GO
ALTER TABLE [Followers] WITH CHECK ADD CONSTRAINT [Followers_fk1] FOREIGN KEY ([ID_Followers]) REFERENCES [Users]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Followers] CHECK CONSTRAINT [Followers_fk1]
GO

ALTER TABLE [Post] WITH CHECK ADD CONSTRAINT [Post_fk0] FOREIGN KEY ([ID_Users]) REFERENCES [Users]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Post] CHECK CONSTRAINT [Post_fk0]
GO
ALTER TABLE [Post] WITH CHECK ADD CONSTRAINT [Post_fk1] FOREIGN KEY ([ID_Themes]) REFERENCES [Themes]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Post] CHECK CONSTRAINT [Post_fk1]
GO

ALTER TABLE [City] WITH CHECK ADD CONSTRAINT [City_fk0] FOREIGN KEY ([ID_Country]) REFERENCES [Country]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [City] CHECK CONSTRAINT [City_fk0]
GO


ALTER TABLE [Rating] WITH CHECK ADD CONSTRAINT [Rating_fk0] FOREIGN KEY ([ID_Users]) REFERENCES [Users]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Rating] CHECK CONSTRAINT [Rating_fk0]
GO
ALTER TABLE [Rating] WITH CHECK ADD CONSTRAINT [Rating_fk1] FOREIGN KEY ([ID_FromWho]) REFERENCES [Users]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Rating] CHECK CONSTRAINT [Rating_fk1]
GO

ALTER TABLE [Likes] WITH CHECK ADD CONSTRAINT [Likes_fk0] FOREIGN KEY ([ID_Users]) REFERENCES [Users]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Likes] CHECK CONSTRAINT [Likes_fk0]
GO
ALTER TABLE [Likes] WITH CHECK ADD CONSTRAINT [Likes_fk1] FOREIGN KEY ([ID_FromWho]) REFERENCES [Users]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Likes] CHECK CONSTRAINT [Likes_fk1]
GO
ALTER TABLE [Likes] WITH CHECK ADD CONSTRAINT [Likes_fk2] FOREIGN KEY ([ID_Post]) REFERENCES [Post]([ID])
ON UPDATE CASCADE
GO
ALTER TABLE [Likes] CHECK CONSTRAINT [Likes_fk2]
GO


USE [TASK]
GO

INSERT INTO [dbo].[Country]
           ([Name])
     VALUES
           ('Россия'), ('Украина'), ('Китай')
GO

INSERT INTO [dbo].[City]
           ([Name]
		   ,[ID_Country])
     VALUES
           ('Саратов', '1'), ('Москва','1'), ('Пекин', '3')		   
GO

INSERT INTO [dbo].[Users]
           ([Name]
		   ,[Date]
		   ,[Address]
		   ,[ID_Country]
		   ,[ID_City]
		   ,[Link]
		   ,[Email])
     VALUES
           ('Бубенчик', '2015-02-13', 'Рахова', '1', '1', 'fglkdhdfhl.com', 'dgjdh@gmail.com')
			,('Бублик', '2014-11-23', 'Москвоская', '2', '2', 'dsd.com', 'oi@gmail.com')
GO

INSERT INTO [dbo].[Comments]
           ([ID_User]
		   ,[Date]
		   ,[Comment])
     VALUES
           ('1', '2015-02-12 12:23', 'Hello')
		   ,('2', '2016-01-12 04:20', 'Its me')
		   ,('3', '2016-01-18 07:00', 'I was wondering if after all')		   
GO

INSERT INTO [dbo].[Themes]
		    ([Name]
		   ,[Description])
     VALUES
            ('Книги', 'Любители книг')
			,('Кино', 'Любители кино')
			,('Музыка', 'Любители музыки')
GO

INSERT INTO [dbo].[Rating]
		    ([ID_Users]
		   ,[ID_FromWho]
		   ,[Mark])
     VALUES
            ('1', '2', '5')
			,('2', '1', '7')
GO

INSERT INTO [dbo].[Followers]
		    ([ID_User]
		   ,[ID_Followers])
     VALUES
            ('1', '2')
			,('2', '1')
GO

INSERT INTO [dbo].[Post]
		    ([ID_Users]
		   ,[ID_Themes]
		   ,[Name]
		   ,[Description]
		   ,[Data])
     VALUES
            ('1', '1', 'Ваши любимые книги', 'Здесь')
			,('2', '3', 'Ваши любимые альбомы', 'Музыка')
GO

INSERT INTO [dbo].[Tags for search]
		    ([Name]
		   ,[ID_Post])
     VALUES
            ('автор', '1')
			,('исполнитель', '3')
GO

INSERT INTO [dbo].[Likes]
		    ([ID_Users]
		   ,[ID_FromWho]
		   ,[ID_Post])
     VALUES
            ('1', '2', '1')
			,('2', '1', '2')
GO


DELETE FROM [dbo].[Country]
      WHERE ID = '2'
GO


DELETE FROM [dbo].[Country]