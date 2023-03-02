import { Image, Text, View } from "react-native";
import styled from "styled-components";

export const BackgroundImage = styled(Image)`
    position: absolute;
    top: 0;
    left: 0;
    bottom: 0;
    right: 0;
`

export const Description = styled(Text)`
    color: white;
    font-family: "BeaufortforLOL-Medium";
    font-size: 20px;
    font-weight: 600;
    margin-top: 15px;
    text-align: center;
`

export const ItemImage = styled(Image)`
    width: 120px;
    height: 120px;
    border-radius: 20px;
    `
    
export const Name = styled(Text)`
    color: white;
    font-family: "BeaufortforLOL-BoldItalic";
    font-size: 35px;
    font-weight: 600;
    margin-top: 15px;
`

export const Price = styled(Text)`
    color: white;
    font-family: "BeaufortforLOL-Bold";
    font-size: 20px;
    font-weight: 600;
`

export const PriceSection = styled(View)`
    display: flex;
    flex-direction: column;
    align-items: center
`

export const PriceTitle = styled(Text)`
    color: white;
    font-family: "BeaufortforLOL-Bold";
    font-size: 30px;
    font-weight: 600;
    margin: 25px 0 10px;
`

export const Tag= styled(Text)`
    background-color: black;
    font-family: "BeaufortforLOL-Bold";
    color: white;
    border-radius: 20px;
    padding: 10px;
    margin: 0 10px;
    opacity: 0.6;
`

export const TagsSection= styled(View)`
    display: flex;
    justify-content: center;
    flex-direction: row;
    margin-top: 20px;
`

export const Wrapper = styled(View)`
    display: flex;
    flex-direction: column;
    align-items: center;
    padding: 20px;
    height: 100%;
    justify-content: center;
`