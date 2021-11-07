--CREATE DATABASE dbSecretariat
--ON
--PRIMARY ( NAME= Secretarrat21,
--FILENAME='D:\Google Classroom\Anul 3\DB\LAB2\Secretariat.mdf',
--SIZE= 10,
--MAXSIZE= 40,
--FILEGROWTH= 2 )
--LOG ON
--( NAME= Secretariat21_log,
--FILENAME ='D:\Google Classroom\Anul 3\DB\LAB2\Secretariat2021log_1.ldf',
--SIZE= 10,
--MAXSIZE= 20,
--FILEGROWTH= 2 )--USE dbSecretariat--CREATE TABLE dbo.tblStudent
--(NrLeg char (8),
--Nume varchar (35),
--Initiala varchar (8),
--Prenume varchar (35),
--Sex char(1),
--DataNastere datetime,
--StareCivila char(1)
--) ON [PRIMARY]

--EXEC sp_help tblStudent

--DROP TABLE dbo.tblStudent;

--CREATE TABLE dbo.tblStudent
--(NrLeg char (8) PRIMARY KEY,
--Nume varchar (35) NOT NULL,
--Initiala varchar (8),
--Prenume varchar (35) NOT NULL,
--Sex char(1) NOT NULL CHECK(Sex IN ('M', 'F')) DEFAULT ('F'),
--DataNastere datetime,
--StareCivila char(1) NOT NULL
--	CHECK(StareCivila IN ('N','C','D','V','M') ) DEFAULT ('N')
--) ON [PRIMARY]

--EXEC sp_help
--EXEC sp_help tblStudent
--EXEC sp_helpconstraint tblStudent

--DROP TABLE dbo.tblStudent;

--CREATE TABLE dbo.tblStudent
--(NrLeg char (8),
--Nume varchar (35) NOT NULL,
--Initiala varchar (8),
--Prenume varchar (35) NOT NULL,
--Sex char(1) NOT NULL DEFAULT ('F'),
--DataNastere datetime,
--StareCivila char(1) NOT NULL DEFAULT ('N'),
--CONSTRAINT conStudent_1 PRIMARY KEy (NrLeg),
--CONSTRAINT conStudent_2 CHECK(Sex IN ('M', 'F')),
--CONSTRAINT conStudent_3 CHECK(StareCivila IN ('N','C','D','V','M') )
--) ON [PRIMARY]

--EXEC sp_help
--EXEC sp_help tblStudent
--EXEC sp_helpconstraint tblStudent

--DROP TABLE dbo.tblStudent;

--CREATE TABLE dbo.tblStudent
--(NrLeg char (8) NOT NULL,
--Nume varchar (35) NOT NULL,
--Initiala varchar (8),
--Prenume varchar (35) NOT NULL,
--Sex char(1) NOT NULL DEFAULT ('F'),
--DataNastere datetime,
--StareCivila char(1) NOT NULL DEFAULT ('N')
--) ON [PRIMARY]

--ALTER TABLE tblStudent
--ADD CONSTRAINT conStudent_1 PRIMARY KEY (NrLeg)

--ALTER TABLE tblStudent WITH CHECK
--ADD CONSTRAINT conStudent_2 CHECK(Sex IN ('M', 'F'))

--ALTER TABLE tblStudent
--ADD CONSTRAINT conStudent_3 CHECK(StareCivila IN ('N','C','D','V','M') )

--EXEC sp_help
--EXEC sp_help tblStudent
--EXEC sp_helpconstraint tblStudent

--ALTER TABLE tblStudent
--ADD CNP char(13) UNIQUE

--ALTER TABLE tblStudent
--ADD Grupa char (5) CHECK (Grupa LIKE '10%')

--EXEC sp_help tblStudent
--EXEC sp_helpconstraint tblStudent

--DROP TABLE dbo.tblStudent;

--CREATE TABLE tblTelefonStud (
--Nrleg char(8) NOT NULL FOREIGN KEY REFERENCES tblStudent(NrLeg)
--ON DELETE CASCADE ON UPDATE CASCADE,
--NrTelefon varchar (10),
--Interior varchar(4),
--Observatii varchar(30) )

--EXEC sp_help tblTelefonStud
--EXEC sp_helpconstraint tblTelefonStud

--DROP TABLE dbo.tblTelefonStud;

--CREATE TABLE tblTelefonStud (
--Nrleg char(8) NOT NULL,
--NrTelefon varchar (10),
--Interior varchar(4),
--Observatii varchar(30) )
--GO
--ALTER TABLE tblTelefonStud
--ADD CONSTRAINT conTel_FK
--FOREIGN KEY (NrLeg) REFERENCES tblStudent(NrLeg)
--ON DELETE CASCADE ON UPDATE CASCADE
--GO--EXEC sp_help tblTelefonStud
--EXEC sp_helpconstraint tblTelefonStud

--DROP TABLE dbo.tblStudent;
--DROP TABLE dbo.tblTelefonStud;

--CREATE TABLE tblStudent (
--NrLeg char (8) PRIMARY KEY CLUSTERED,
--CNP varchar (13) UNIQUE,
--NumeStudent varchar (40) NOT NULL,
--InitialaStudent varchar (6),
--Prenumestudent varchar(40) NOT NULL,
--Sex char (1) CHECK (Sex IN ('M', 'F'))DEFAULT ('M'),
--DataNastere datetime,
--GrupaSange varchar (3),
--StareCiviLa char (1) CHECK (StareCivila IN ('C', 'D', 'M', 'N', 'V')),
--SituatieMilitara char (1) CHECK (SituatieMilitara IN ('I', 'N') ) ,
--Grupa char (5) CHECK (Grupa LIKE '10%')
--)
--CREATE TABLE tblMaterie (
--ID_Materie char(6) PRIMARY KEY CLUSTERED,
--NumeMaterie varchar(30) NOT NULL,
--Semestrul varchar (2) NOT NULL,
--OreCurs tinyint,
--OreSeminar tinyint,
--Orelaborator tinyint,
--OreProiect tinyint,
--TipMaterie varchar(1) CHECK(TipMaterie IN ('F','N','O'))
--DEFAULT ( 'N'),
--FormaExaminare varchar (3) CHECK (FormaExaminare IN ( 'E','CFN','CN' ) )
--DEFAULT('E'),
--Credit tinyint CHECK (Credit BETWEEN 1 AND 6 )
--)
--CREATE TABLE tblStudiaza (
--Nrleg char(8)NOT NULL REFERENCES tblStudent(NrLeg)
--ON DELETE CASCADE ON UPDATE CASCADE,
--ID_Materie char ( 6) NOT NULL REFERENCES tblMaterie (ID_Materie)
--ON DELETE CASCADE ON UPDATE CASCADE
--)--DROP TABLE tblStudiaza;--DROP TABLE tblStudent;--DROP TABLE tblMaterie;--sp_addtype tipNrLegStud,
--'char (8)','NOT NULL','dbo'--EXEC sp_help--CREATE TABLE dbo.tblStudent
--(NrLeg char (8) PRIMARY KEY ,
--Nume varchar (35) NOT NULL,
--Initiala varchar(8),
--Prenume varchar (35) NOT NULL,
--Sex char(1)NOT NULL CHECK(Sex IN ('M','F')) DEFAULT ('F'),
--DataNastere datetime,
--StareCivila char(1) NOT NULL
--CHECK(StareCivila IN ('N','C','D','V','M') )DEFAULT ('N')
--) ON [PRIMARY]
--GO
--CREATE TABLE dbo.tblTelefonStud (
--NrLeg tipNrLegStud,
--NrTelefon varchar (10),
--Interior varchar (4),
--Observatii varchar(30)
--CONSTRAINT conTelstud FOREIGN KEY (NrLeg) REFERENCES tblStudent (Nrleg)
--ON DELETE CASCADE ON UPDATE CASCADE
--)
--GO

--EXEC sp_help

 --EXEC sp_helpconstraint

--CREATE RULE ruleSex
--AS @sex IN ('F','M')
--CREATE RULE ruleStareClvila
--AS @StareCivila IN ('N','C','D','V','M')

--EXEC sp_helptext

--CREATE DEFAULT defSex AS 'M'
--GO
--CREATE DEFAULT defStareCivila AS 'N'

--CREATE TABLE dbo.tblStudent
--(NrLeg tipNrLegStud PRIMARY KEY ,
--Nume varchar (35) NOT NULL,
--Initiala varchar (8),
--Prenume varchar (35) NOT NULL,
--Sex char(1)NOT NULL,
--DataNastere datetime,
--StareCivila char(1) NOT NULL
--) ON [PRIMARY]

--EXEC sp_bindrule ruleSex,'dbo.tblStudent.Sex'
--EXEC sp_bindrule rulestarecivila ,
--'dbo.tblStudent.StareCivila'
--EXEC sp_bindefauLt defSex,'dbo.tblStudent.Sex'
--EXEC sp_bindefault defStareCivila,'dbo.tblStudent.StareCivila'

--EXEC sp_helpconstraint tblStudent

--CREATE TABLE #tblStudentRepetent
--(NrLeg tipNrLegStud PRIMARY KEY,
--Nume varchar (35) NOT NULL,
--Initiala varchar (8),
--Prenume varchar (35) NOT NULL,
--Sex char(1)NOT NULL,
--DataNastere datetime,
--StareCivila char(1) NOT NULL
--) ON [PRIMARY]--DROP DATABASE dbSecretariat