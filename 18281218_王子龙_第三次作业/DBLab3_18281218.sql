create table Train_Info
(
    TrainNumber      varchar(7)    not null,
    DepartureStation varchar(1000) not null,
    ArrivalStation   varchar(1000) not null,
    Duration         int           not null,
    isGaotie         tinyint(1)    not null,
    constraint Train_Info_TrainNumber_uindex
        unique (TrainNumber)
);

alter table Train_Info
    add primary key (TrainNumber);

create table User_Info
(
    username     varchar(100) not null,
    password     varchar(100) not null,
    name         varchar(100) not null,
    phoneNumber  varchar(20)  not null,
    emailAddress varchar(100) not null,
    ID           varchar(25)  not null,
    Type         int          not null,
    IDType       int          not null,
    constraint User_Info_ID_uindex
        unique (ID),
    constraint User_Info_username_uindex
        unique (username)
);

alter table User_Info
    add primary key (ID);

create table Remaining_Tickets
(
    TrainNumber           varchar(7)  not null,
    DepartureStation      varchar(15) not null,
    ArrivalStation        varchar(15) not null,
    SpecialClassRemaining int         not null,
    FirstClassRemaining   int         not null,
    SecondClassRemaining  double      not null,
    SecondClassFare       int         not null,
    FirstClassFare        double      not null,
    SpecialClassFare      double      not null,
    primary key (TrainNumber, DepartureStation, ArrivalStation),
    constraint Remaining_Tickets_Train_Info_TrainNumber_fk
        foreign key (TrainNumber) references Train_Info (TrainNumber)
);


create table Way_Station
(
    TrainNumber     varchar(7)  not null,
    Station1        varchar(15) not null,
    ArrivalTime1    datetime    not null,
    DepartureTime1  datetime    not null,
    Station2        varchar(15) not null,
    ArrivalTime2    datetime    not null,
    DepartureTime2  datetime    not null,
    Station3        varchar(15) null,
    ArrivalTime3    datetime    null,
    DepartureTime3  datetime    null,
    Station4        varchar(15) null,
    ArrivalTime4    datetime    null,
    DepartureTime4  datetime    null,
    Station5        varchar(15) null,
    ArrivalTime5    datetime    null,
    DepartureTime5  datetime    null,
    Station6        varchar(15) null,
    ArrivalTime6    datetime    null,
    DepartureTime6  datetime    null,
    Station7        varchar(15) null,
    ArrivalTime8    datetime    null,
    DepartureTime8  datetime    null,
    Station9        varchar(15) null,
    ArrivalTime9    datetime    null,
    DepartureTime9  datetime    null,
    Station10       varchar(15) null,
    ArrivalTime10   datetime    null,
    DepartureTime10 datetime    null,
    Station11       varchar(15) null,
    ArrivalTime11   datetime    null,
    DepartureTime11 datetime    null,
    Station12       varchar(15) null,
    ArrivalTime12   datetime    null,
    DepartureTime12 datetime    null,
    Station13       varchar(15) null,
    ArrivalTime13   datetime    null,
    DepartureTime13 datetime    null,
    Station14       varchar(15) null,
    ArrivalTime14   datetime    null,
    DepartureTime14 datetime    null,
    Station15       varchar(15) null,
    ArrivalTime15   datetime    null,
    DepartureTime15 datetime    null,
    Station16       varchar(15) null,
    ArrivalTime16   datetime    null,
    DepartureTime16 datetime    null,
    Station17       varchar(15) null,
    ArrivalTime17   datetime    null,
    DepartureTime17 datetime    null,
    Station18       varchar(15) null,
    ArrivalTime18   datetime    null,
    DepartureTime18 datetime    null,
    Station19       varchar(15) null,
    ArrivalTime19   datetime    null,
    DepartureTime19 datetime    null,
    Station20       varchar(15) null,
    ArrivalTime20   datetime    null,
    DepartureTime20 datetime    null,
    Station21       varchar(15) null,
    ArrivalTime21   datetime    null,
    DepartureTime21 datetime    null,
    Station22       varchar(15) null,
    ArrivalTime22   datetime    null,
    DepartureTime22 datetime    null,
    Station23       varchar(15) null,
    ArrivalTime23   datetime    null,
    DepartureTime23 datetime    null,
    Station24       varchar(15) null,
    ArrivalTime24   datetime    null,
    DepartureTime24 datetime    null,
    Station25       varchar(15) null,
    ArrivalTime25   datetime    null,
    DepartureTime25 datetime    null,
    Station26       varchar(15) null,
    ArrivalTime26   datetime    null,
    DepartureTime26 datetime    null,
    Station27       varchar(15) null,
    ArrivalTime27   datetime    null,
    DepartureTime27 datetime    null,
    Station28       varchar(15) null,
    ArrivalTime28   datetime    null,
    DepartureTime28 datetime    null,
    Station29       varchar(15) null,
    ArrivalTime29   datetime    null,
    DepartureTime29 datetime    null,
    Station30       varchar(15) null,
    ArrivalTime30   datetime    null,
    DepartureTime30 datetime    null,
    Station31       varchar(15) null,
    ArrivalTime31   datetime    null,
    DepartureTime31 datetime    null,
    Station32       varchar(15) null,
    ArrivalTime32   datetime    null,
    DepartureTime32 datetime    null,
    Station33       varchar(15) null,
    ArrivalTime33   datetime    null,
    DepartureTime33 datetime    null,
    Station34       varchar(15) null,
    ArrivalTime34   datetime    null,
    DepartureTime34 datetime    null,
    Station35       varchar(15) null,
    ArrivalTime35   datetime    null,
    DepartureTime35 datetime    null,
    Station36       varchar(15) null,
    ArrivalTime36   datetime    null,
    DepartureTime36 datetime    null,
    Station37       varchar(15) null,
    ArrivalTime37   datetime    null,
    DepartureTime37 datetime    null,
    Station38       varchar(15) null,
    ArrivalTime38   datetime    null,
    DepartureTime38 datetime    null,
    constraint Way_Station_TrainNumber_uindex
        unique (TrainNumber),
    constraint Way_Station_Train_Info_TrainNumber_fk
        foreign key (TrainNumber) references Train_Info (TrainNumber)
);

alter table Way_Station
    add primary key (TrainNumber);

