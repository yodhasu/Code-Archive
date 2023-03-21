function validate(){
    let name = document.getElementById('userName').value;
    let email = document.getElementById('userEmail').value;
    var symbols = /^[A-Za-z]+$/;

    // if(name == ""){
        // document.getElementById("userNameerror").innerText = "Please enter your name."
        // return false
    // }
	
	// else if(name.match(symbols)){
        // document.getElementById("userNameerror").innerText = "Please enter your name."
        // return false		
		// }
    // // else if(name == /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/){
        // // document.getElementById("userNameerror").innerText = "Please enter a valid name."
        // // return false
    // // }
    // else{
        // document.getElementById("userNameerror").innerText = ""
    // }
		
	if( document.myform.userName.value == "" ) {
            document.getElementById("userNameerror").innerText = "Please enter your name";
            document.myform.userName.focus() ;
            return false;
			
	}
	if( document.myform.userEmail.value == "" ) {
            document.getElementById("userEmailerror").innerText = "Please enter your email";
            document.myform.userEmail.focus() ;
			return false
	}
	// if( document.myform.userGender.checked == false ) {
            // document.getElementById("userGendererror").innerText = "Please enter your email";
            // document.myform.userGender.checked() ;
			// return false
	// }
    return true
}
