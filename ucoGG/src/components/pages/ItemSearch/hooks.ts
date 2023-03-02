import { useState } from "react";


export const useItemSearch = (navigation: any)=>{

    const [itemName, setItemName] = useState<string>()

    const handleChange = (value: string)=>{
        setItemName(value)
    }

    const handleSearchPress = ()=>{
        navigation.navigate('ItemScreen', {itemName})
    }

    return {
        handleChange,
        handleSearchPress
    }
}