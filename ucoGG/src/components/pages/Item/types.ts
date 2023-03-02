export type ItemProps = {
    icon: string,
    name: string,
    plaintext: string,
    price: PriceProps,
    stats: any,
    tags: string[]
}

export type PriceProps = {
    base: number,
    sell: number,
    total: number
}

