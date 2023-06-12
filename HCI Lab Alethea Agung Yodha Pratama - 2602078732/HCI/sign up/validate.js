function validate(){
    var symbols = /[^a-z_\s]/i;
    var emailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
    
    // if (document.myform.Male.checked){
    //     Gender = document.getElementById("Male").value
    // }
    // else if (document.myform.Female.checked){
    //     Gender = document.getElementById("Female").value
    // }

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
    else if( document.myform.userName.value.match(symbols)) {
        document.getElementById("userNameerror").innerText = "Please enter valid name";
        document.myform.userName.focus() ;
        return false;
        
    }
    else{
        document.getElementById("userNameerror").innerText = "";
        document.myform.userName.focus() ;
        
    }
	
	if( document.myform.userGender.value == "" ) {
            document.getElementById("userGendererror").innerText = "Please select your gender";
			return false
	}
    else{
        document.getElementById("userGendererror").innerText = "";
    }
    
    // if (Gender == ""){
    //     document.getElementById("userGendererror").innerText = "Please select your gender";
    //     document.myform.userGender.checked() ;
    //     return false
    // }
    // else{
    //     document.getElementById("userGendererror").innerText = "";
    //     document.myform.userGender.focus() ;
    // }

    if( document.myform.userPassword.value == "" ) {
        document.getElementById("userPassworderror").innerText = "Please enter your password";
        document.myform.userPassword.focus() ;
        return false
    }
    else if( document.myform.userPassword.value.length < 8 ) {
        document.getElementById("userPassworderror").innerText = "Password must have atleast 8 characters";
        document.myform.userPassword.focus() ;
        return false
    }
    else {
        document.getElementById("userPassworderror").innerText = "";
        document.myform.userPassword.focus() ;
    }
    if( document.myform.userPassword.value.search(/[A-Z]/) == -1 ) {
        document.getElementById("userPassworderror2").innerText = "Password must have atleast 1 capital characters";
        document.myform.userPassword.focus() ;
        return false
    }
    else if( document.myform.userPassword.value.search(/[0-9]/) == -1 ) {
        document.getElementById("userPassworderror2").innerText = "Password must have atleast 1 number";
        document.myform.userPassword.focus() ;
        return false
    }
    else {
        document.getElementById("userPassworderror2").innerText = "";
    }

    if( document.myform.userConfirmPassword.value == "" ) {
        document.getElementById("userConfirmPassworderror").innerText = "Please re-enter your password";
        document.myform.userConfirmPassword.focus() ;
        return false
    }
    else if( document.myform.userConfirmPassword.value != document.myform.userPassword.value ) {
        document.getElementById("userConfirmPassworderror").innerText = "Password did not match";
        document.myform.userConfirmPassword.focus() ;
        return false
    }
    else {
        document.getElementById("userConfirmPassworderror").innerText = "";
        document.myform.userConfirmPassword.focus() ;
            
    }
    window.location.assign("..//Movie/Movie.html"); 
    return false;
}
