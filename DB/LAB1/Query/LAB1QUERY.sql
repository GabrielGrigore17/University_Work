 --GRIGORE SANDI GABRIEL CEN 3.2 A
 --LAB 1
 
 --CREATE DATABASE Secretariat;
--EXEC sp_helpdb;--EXEC sp_helpdb Secretariat;--DROP DATABASE Secretariat;--EXEC sp_helpdb;--CREATE DATABASE dbSecretariat
--ON
--(NAME=Secretariat ,
--FILENAME='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat.mdf' );

--DROP DATABASE dbSecretariat;

--CREATE DATABASE dbSecretariat
--ON
--(NAME=Secretariat ,
--FILENAME='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat.mdf',
--SIZE = 10,
--MAXSIZE = 20,
--FILEGROWTH = 2);

--EXEC sp_helpdb dbSecretariat;

--DROP DATABASE dbSecretariat;

--CREATE DATABASE dbSecretariat
--ON
--	(NAME=Secretariat2021,
--	FILENAME='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat2021date.mdf',
--	SIZE = 10,
--	MAXSIZE = 20,
--	FILEGROWTH = 2 )
--LOG ON
--	(NAME=Secretariat2021log,
--	FILENAME='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat2021log.ldf',
--	SIZE = 10,
--	MAXSIZE = 20,
--	FILEGROWTH = 500KB);

--EXEC sp_helpdb dbSecretariat;

--DROP DATABASE dbSecretariat;

--CREATE DATABASE dbSecretariat
--ON
--PRIMARY ( NAME = Secretariat21,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat_1.mdf',
--	SIZE = 10,
--	MAXSIZE = 40,
--	FILEGROWTH = 2),
--FILEGROUP data2_file_grup
--( NAME = Secretariat21_2,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat_2.ndf',
--	SIZE = 10,
--	MAXSIZE = 20,
--	FILEGROWTH = 2),
--( NAME = Secretariat21_3,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat_3.ndf',
--	SIZE = 10,
--	MAXSIZE = 20,
--	FILEGROWTH = 2)
--LOG ON
--( NAME = Secretariat21_log1,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat2021log_1.ldf',
--	SIZE = 10,
--	MAXSIZE = 20,
--	FILEGROWTH = 2),
--( NAME = Secretariat21_log2,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat2021log_2.ldf',
--	SIZE = 10,
--	MAXSIZE = 20,
--	FILEGROWTH = 5%);

--EXEC sp_helpdb dbSecretariat;

--USE dbSecretariat;

--EXECUTE sp_helpfilegroup;

--EXECUTE sp_helpfile;--ALTER DATABASE dbSecretariat
--MODIFY NAME=dbSecretariat21_22;--EXEC sp_helpdb;--ALTER DATABASE dbSecretariat21_22
--ADD FILE
--( NAME = secretariat,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat.ndf',
--	SIZE = 10,
--	MAXSIZE = 20,
--	FILEGROWTH = 2);--EXECUTE sp_helpfilegroup;

--EXECUTE sp_helpfile;

--ALTER DATABASE dbSecretariat21_22
--REMOVE FILE Secretariat;--EXECUTE sp_helpfilegroup;

--EXECUTE sp_helpfile;

--ALTER DATABASE dbSecretariat21_22
--ADD FILE
--( NAME = secretariat,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\Secretariat.ndf',
--	SIZE = 10,
--	MAXSIZE = 20,
--	FILEGROWTH = 2)
--TO FILEGROUP data2_file_grup;

--EXECUTE sp_helpfilegroup;

--EXECUTE sp_helpfile;

--ALTER DATABASE dbSecretariat21_22
--MODIFY FILE (NAME = secretariat, NEWNAME = secretariat21_22);

--EXECUTE sp_helpfile;

--ALTER DATABASE dbSecretariat21_22
--MODIFY FILE
--( NAME = secretariat21_22,
--SIZE = 1536KB,
--MAXSIZE = 12,
--FILEGROWTH = 768KB);--This command failed as expected!--ALTER DATABASE dbSecretariat21_22
--MODIFY FILE
--( NAME = secretariat21_22,
--SIZE = 11776KB,
--MAXSIZE = 21,
--FILEGROWTH = 768KB);--This command succedeed as expected!--EXECUTE sp_helpfile;

--DROP DATABASE dbSecretariat21_22;

--CREATE DATABASE dbTestl
--ON
--PRIMARY (NAME=FisierDate1,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\fisier1.mdf',
--	SIZE = 1,
--	MAXSIZE = 3
--	),
--	(NAME=FisierDate2,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\fisier2.mdf',
--	SIZE = 1,
--	MAXSIZE = 3
--	),
--	(NAME=FisierDate3,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\fisier3.mdf',
--	SIZE = 1,
--	MAXSIZE = 3
--	);
--EXECUTE sp_helpdb;

--EXECUTE sp_helpfile;

--EXEC sp_detach_db 'dbTestl';

--EXECUTE sp_helpdb;

--EXECUTE sp_helpfile;

--DROP DATABASE dbTestl;

--CREATE DATABASE dbTest2
--ON
--PRIMARY (NAME=FisierDate1,
--	FILENAME ='D:\Google Classroom\Anul 3\DB\LAB1\fisier1.mdf',
--	SIZE = 1,
--	MAXSIZE = 3
--	)
--FOR ATTACH;

--EXECUTE sp_helpdb;

--EXECUTE sp_helpfile;

--ALTER DATABASE dbTest2
--SET RECOVERY FULL;

--EXECUTE sp_helpdb;

--DROP DATABASE dbTest2;