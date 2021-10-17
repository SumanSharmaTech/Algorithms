function reverseStr(str){
    let tempStr = ""
    for (const item in str) {
        tempStr = tempStr + str[str.length - 1 - item]
    }

    return tempStr
}

function palindrome (str) {
    let reversed = reverseStr(str)
    if (reversed === str) {
        return true
    }

    return false
}

