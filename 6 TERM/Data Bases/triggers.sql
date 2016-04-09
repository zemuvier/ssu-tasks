USE[TASK]
GO
CREATE TRIGGER MyTriggerForDelete1
   ON City
   AFTER DELETE
AS
BEGIN
	BEGIN TRY
		SET NOCOUNT ON;
		if (select ID from deleted) > '0'
		BEGIN
		rollback
		print 'Нельзя удалять запись, id больше 0!'
		END
	END TRY
	BEGIN CATCH
		print 'Ошибка!';
		THROW
	END CATCH
END

GO
CREATE TRIGGER MyTriggerForDelete2
   ON Rating
   AFTER DELETE
AS
BEGIN
	BEGIN TRY
		SET NOCOUNT ON;
		if (select Mark from deleted) < 11
		BEGIN
		rollback
		print 'НЕЛЬЗЯ!'
		END
	END TRY
	BEGIN CATCH
		print 'Ошибка!';
		THROW
	END CATCH
END

GO
CREATE TRIGGER MyTriggerForDelete3
   ON Themes
   AFTER DELETE
AS
BEGIN
	BEGIN TRY
		SET NOCOUNT ON;
		if (select ID from deleted) > '0'
		BEGIN
		rollback
		print 'Нельзя!'
		END
	END TRY
	BEGIN CATCH
		print 'Ошибка!';
		THROW
	END CATCH
END




GO
CREATE TRIGGER MyTriggerForInsert1
   ON Rating
   AFTER INSERT
AS
BEGIN
	BEGIN TRY
		SET NOCOUNT ON;	
		if (select Mark from inserted) > '10'
		BEGIN
		rollback
		print 'Оценка слишком велика!'
		END
	END TRY
	BEGIN CATCH
		print 'Ошибка!';
		THROW
	END CATCH
END

GO
CREATE TRIGGER MyTriggerForInsert2
   ON Rating
   AFTER INSERT
AS
BEGIN
	BEGIN TRY
		SET NOCOUNT ON;
		if (select Mark from inserted) < '0'
		BEGIN
		rollback
		print 'Оценка слишком мала!'
		END
	END TRY
	BEGIN CATCH
		print 'Ошибка!';
		THROW
	END CATCH
END

GO
CREATE TRIGGER MyTriggerForInsert3
   ON Comments
   AFTER INSERT
AS
BEGIN
	BEGIN TRY
		SET NOCOUNT ON;
		if (select Date from inserted) <= GETDATE()
		BEGIN
		rollback
		print 'Дата должна быть меньше!'
		END
	END TRY
	BEGIN CATCH
		print 'Ошибка!';
		THROW
	END CATCH
END






GO
CREATE TRIGGER MyTriggerForUpdate1
   ON Rating
   AFTER UPDATE
AS
BEGIN
	BEGIN TRY
		SET NOCOUNT ON;
		IF (SELECT Mark FROM updated) > '10'
		BEGIN
		rollback
		print 'Оценка слишком велика!'
		END
	END TRY
	BEGIN CATCH
		print 'Ошибка!';
		THROW
	END CATCH
END

GO
CREATE TRIGGER MyTriggerForUpdate2
   ON Rating
   AFTER UPDATE
AS
BEGIN
	BEGIN TRY
		SET NOCOUNT ON;
		IF (SELECT Mark FROM updated) < '0'
		BEGIN
		rollback
		print 'Оценка слишком мала!'
		END
	END TRY
	BEGIN CATCH
		print 'Ошибка!';
		THROW
	END CATCH
END

GO
CREATE TRIGGER MyTriggerForUpdate3
   ON Comments
   AFTER UPDATE
AS
BEGIN
	BEGIN TRY
		SET NOCOUNT ON;
		if (select Date from updated) > GETDATE()
		BEGIN
		rollback
		print 'Дата должна быть меньше!'
		END
	END TRY
	BEGIN CATCH
		print 'Ошибка!';
		THROW
	END CATCH
END
