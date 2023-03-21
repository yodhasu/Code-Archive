+ function($) {
  $('.palceholder').click(function() {
    $(this).siblings('input').focus();
  });

  $('.form-control').focus(function() {
    $(this).parent().addClass("focused");
  });

  $('.form-control').blur(function() {
    var $this = $(this);
    if ($this.val().length == 0)
      $(this).parent().removeClass("focused");
  });
  $('.form-control').blur();

  // validetion
  $.validator.setDefaults({
    errorElement: 'span',
    errorClass: 'validate-tooltip'
  });

  $("#formvalidate").validate({
    rules: {
      userName: {
        required: true,
      },
      userEmail: {
        required: true,
      },
      userGender: {
        required: true,
      },
      userCity: {
        required: true,
      },
      userPassword: {
        required: true,

      }
    },
    messages: {
      userName: {
        required: "*Please enter your name.",
      },
      userEmail: {
        required: "*Please enter your email.",
      },
      userGender: {
        required: "*Please select your gender.",
      },
      userCity: {
        required: "*Please select your city.",
      },
      userPassword: {
        required: "*Enter your password to register.",
      }
    }
  });

}(jQuery);