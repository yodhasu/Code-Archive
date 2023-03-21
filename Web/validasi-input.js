// let number = 5
// let number2 = 0

// var var3 = "Text"
// const var4 = 82
// Variable yang tidak bisa diganti

// if(number2 > 1){
//     console.log(number2 + " lebih besar dari 1")
// }
// else if(number2 == 1){
//     console.log(number2 + " sama dengan 1")
// }
// else{
//     console.log(number2 + " kurang dari 1")
// }

// for(let i = 0; i < number; i++){
//     let nilaiLoop = i
// }

// while(number > 1){
//     console.log(number)
//     number--
// }

// let array = [1, 2, 3, 4, 5]

// array.forEach((value, index) => {
//     console.log(value)
// })

// let objek = [
//     {
//         nama: "Roger",
//         umur: 19
//     },
//     {
//         nama: "Ivan",
//         umur: 20
//     }
// ]

// objek.map((value, index) => {
//     console.log(index+1 + ". " + value.nama)
// })

function validasi(){
    // Nama: "   Roger julianto      "

    let namaLengkap = document.getElementById("nama").value.trim()
    let email = document.getElementById("email").value.trim()
    let jenisKelamin = ""

    if(document.getElementById("Pria").checked){
        jenisKelamin = document.getElementById("Pria").value
    }
    else if(document.getElementById("Wanita").checked){
        jenisKelamin = document.getElementById("Wanita").value
    }

    let pesan = document.getElementById("pesan").value.trim()

    // let formItem = document.getElementsByClassName("formItem")

    // console.log(formItem)

    // formItem.forEach((value, idx) => {
    //     console.log(value)
    // })
    // for(let i = 0; i < formItem.length; i++){
    //     formItem[i].innerHTML = `
    //         <p>Ganti Isi HTML</p>
    //     `
    // }

    // Nama Lengkap -> Required, Minimal 5 huruf
    if(namaLengkap == ""){
        document.getElementById("err-nama").innerText = "Nama Wajib Diisi!"
        return false
    }
    else if(namaLengkap.length < 5){
        alert("Nama harus minimal 5 huruf")
        return false
    }
    else{
        document.getElementById("err-nama").innerText = ""
    }

    // Email -> Required, harus mengandung hanya 1 @, di depan @ harus ada teks, di belakang @ harus ada teks dan mengandung . (bukan setelah @)
    if(email == ""){
        alert("Email harus diisi!")
        return false
    }
    // Split -> Membagi suatu variable/string menjadi array sesuai dengan pembatas yang dimasukkan
    // let email = "roger@binus.ac.id"
    // let hasilSplit = email.split("@")
    // hasilSplit = ["roger", "binus.ac.id"]

    else if(email.split("@").length !== 2){
        alert("Email harus berisikan satu @")
        return false
    }
    else if(email.split("@")[0].length === 0){
        alert("Di depan @ harus ada teks")
        return false
    }
    else if(email.split("@")[1].length === 0){
        alert("Di belakang @ harus ada teks")
        return false
    }
    // Includes mengecek suatu string apakah memiliki string yang dimasukkan di dalam includes
    // let email = "roger@binus.ac.id"
    // email.includes(".ac.id") -> true
    else if(!email.split("@")[1].includes(".")){
        alert("Di belakang @ harus ada .")
        return false
    }
    else if(email.split("@")[1][0] === '.'){
        alert(". tidak boleh terletak tepat setelah @")
        return false
    }

    // Jenis Kelamin pastiin ada isi
    if(jenisKelamin == ""){
        alert("Jenis Kelamin harus dipilih!")
        return false
    }

    // Pesan harus diisi dan minimal 20 huruf
    if(pesan == ""){
        alert("Pesan harus diisi!")
        return false
    }
    else if(pesan.length < 20){
        alert("Pesan harus minimal 20 huruf")
        return false
    }

    alert("Form berhasil dikirim!")
    return true
}