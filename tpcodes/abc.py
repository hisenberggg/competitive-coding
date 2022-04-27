user: userid username

contactdetails : fk(userid) contactno

select username from user where user.userid = contactdetails.userid;
selet user.userid,contactdetails.userid from user leftjoin contactdetails on user.userid = contactdetails.userid where contactdetails.userid=null;

1 2 3 4
1 3

1 2 3 4
