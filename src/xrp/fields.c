/*******************************************************************************
 *   XRP Wallet
 *   (c) 2020 Towo Labs
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#include <string.h>

#include "fields.h"
#include "flags.h"
#include "common.h"

#define HIDE(t, i) \
    if (field->data_type == (t) && field->id == (i) && field->array_info.type == 0) return true

bool is_normal_account_field(field_t *field) {
    return field->data_type == STI_ACCOUNT && field->id == XRP_ACCOUNT_ACCOUNT &&
           field->array_info.type == 0;
}

const char *resolve_field_name(field_t *field) {
    if (field->data_type == STI_UINT16) {
        switch (field->id) {
            case 1:
                return "Ledger Entry Type";
            case 2:
                return "Transaction Type";
            case 3:
                return "Signer Weight";
            case 4:
                return "Transfer Fee";
            case 5:
                return "Trading Fee";
            case 6:
                return "Discount Fee";
            case 16:
                return "Version";
        }
    }

    if (field->data_type == STI_UINT32) {
        switch (field->id) {
            // 32-bit integers
            case 1:
                return "Network ID";
            case 2:
                return "Flags";
            case 3:
                return "Source Tag";
            case 4:
                return "Sequence";
            case 5:
                return "Previous Txn Lgr Seq";
            case 6:
                return "Ledger Sequence";
            case 7:
                return "Close Time";
            case 8:
                return "Parent Close Time";
            case 9:
                return "Signing Time";
            case 10:
                return "Expiration";
            case 11:
                return "Transfer Rate";
            case 12:
                return "Wallet Size";
            case 13:
                return "Owner Count";
            case 14:
                return "Destination Tag";
            case 16:
                return "High Quality In";
            case 17:
                return "High Quality Out";
            case 18:
                return "Low Quality In";
            case 19:
                return "Low Quality Out";
            case 20:
                return "Quality In";
            case 21:
                return "Quality Out";
            case 22:
                return "Stamp Escrow";
            case 23:
                return "Bond Amount";
            case 24:
                return "Load Fee";
            case 25:
                return "Offer Sequence";
            case 26:
                return "First Ledger Sequence";
            case 27:
                return "Last Ledger Sequence";
            case 28:
                return "Transaction Index";
            case 29:
                return "Operation Limit";
            case 30:
                return "Reference Fee Units";
            case 31:
                return "Reserve Base";
            case 32:
                return "RReserve Increment";
            case 33:
                return "Set Flag";
            case 34:
                return "Clear Flag";
            case 35:
                return "Signer Quorum";
            case 36:
                return "Cancel After";
            case 37:
                return "Finish After";
            case 38:
                return "Signer List ID";
            case 39:
                return "Settle Delay";
            case 40:
                return "Ticket Count";
            case 41:
                return "Ticket Sequence";
            case 42:
                return "NFToken Taxon";
            case 43:
                return "Minted NFTokens";
            case 44:
                return "Burned NFTokens";
            // break
            case 46:
                return "Emit Generation";
            case 48:
                return "Vote Weight";
            // break
            case 50:
                return "First NFToken Sequence";
        }
    }

    if (field->data_type == STI_HASH128) {
        switch (field->id) {
            case 1:
                return "Email Hash";
        }
    }

    if (field->data_type == STI_HASH256) {
        switch (field->id) {
            // 256-bit
            case 1:
                return "Ledger Hash";
            case 2:
                return "Parent Hash";
            case 3:
                return "Transaction Hash";
            case 4:
                return "Account Hash";
            case 5:
                return "Previous Txn ID";
            case 6:
                return "Ledger Index";
            case 7:
                return "Wallet Locator";
            case 8:
                return "Root Index";
            case 9:
                return "Account Txn ID";
            case 10:
                return "NFToken ID";
            // break
            case 14:
                return "AMM ID";
            // break
            case 16:
                return "Book Directory";
            case 17:
                return "Invoice ID";
            case 18:
                return "Nickname";
            case 19:
                return "Amendment";
            // break
            case 21:
                return "Digest";
            case 22:
                return "Channel";
            case 23:
                return "Consensus Hash";
            case 24:
                return "Check ID";
            case 25:
                return "Validated Hash";
            case 26:
                return "Previous Page Min";
            case 27:
                return "Next Page Min";
            case 28:
                return "NFToken Offer";
            case 29:
                return "NFToken Offer";
            // break
        }
    }

    if (field->data_type == STI_AMOUNT) {
        switch (field->id) {
            // currency amount
            case 1:
                return "Amount";
            case 2:
                return "Balance";
            case 3:
                return "Limit Amount";
            case 4:
                return "Taker Pays";
            case 5:
                return "Taker Gets";
            case 6:
                return "Low Limit";
            case 7:
                return "HighLimit";
            case 8:
                return "Fee";
            case 9:
                return "Send Max";
            case 10:
                return "Deliver Min";
            // break
            case 11:
                return "Amount 2";
            case 12:
                return "Bid Min";
            case 13:
                return "Bid Max";
            // break
            case 16:
                return "Minimum Offer";
            case 17:
                return "Ripple Escrow";
            case 18:
                return "Delivered Amount";
            case 19:
                return "NFToken Broker Fee";
            // break
            case 22:
                return "Base Fee Drops";
            case 23:
                return "Reserve Base Drops";
            case 24:
                return "Reserve Increment Drops";
            case 25:
                return "LP Token Out";
            case 26:
                return "LP Token In";
            case 27:
                return "E Price";
            case 28:
                return "Price";
            case 29:
                return "Signature Reward";
            case 30:
                return "Create Amount";
            case 31:
                return "LP Token Balance";
        }
    }

    if (field->data_type == STI_VL) {
        switch (field->id) {
            // variable length (common)
            case 1:
                return "Public Key";
            case 2:
                return "Message Key";
            case 3:
                return "Sig.PubKey";
            case 4:
                return "Txn Sig.";
            case 5:
                return "URI";
            case 6:
                return "Signature";
            case 7:
                return "Domain";
            case 8:
                return "Fund Code";
            case 9:
                return "Remove Code";
            case 10:
                return "Expire Code";
            case 11:
                return "Create Code";
            case 12:
                return "Memo Type";
            case 13:
                return "Memo Data";
            case 14:
                return "Memo Fmt";
            case 16:
                return "Fulfillment";
            case 17:
                return "Condition";
            case 18:
                return "Master Sig.";
            case 19:
                return "UNLModify Validator";
            case 20:
                return "Validator To Disable";
            case 21:
                return "Validator To Re Enable";
            // break
            case 26:
                return "DID Document";
            case 27:
                return "Data";
        }
    }

    if (field->data_type == STI_VECTOR256) {
        switch (field->id) {
            // vector 256
            case 1:
                return "Indexes";
            case 2:
                return "Hashes";
            case 3:
                return "Amendments";
            case 4:
                return "NFToken Offers";
        }
    }

    if (field->data_type == STI_ACCOUNT) {
        switch (field->id) {
            case 1:
                return "Account";
            case 2:
                return "Owner";
            case 3:
                return "Destination";
            case 4:
                return "Issuer";
            case 5:
                return "Authorize";
            case 6:
                return "Unauthorize";
            // break
            case 8:
                return "Regular Key";
            case 9:
                return "NFToken Minter";
            // break
            case 18:
                return "Other Chain Source";
            case 19:
                return "Other Chain Destination";
            case 20:
                return "Attestation Signer Account";
            case 21:
                return "Attestation Reward Account";
            case 22:
                return "Locking Chain Door";
            case 23:
                return "Issuing Chain Door";
        }
    }

    if (field->data_type == STI_OBJECT) {
        switch (field->id) {
            // inner object
            // OBJECT/1 is reserved for end of object
            // break
            case 10:
                return "Memo";
            case 11:
                return "Signer Entry";
            case 12:
                return "NFToken";
            // break
            case 16:
                return "Signer";
            // break
            case 25:
                return "Vote Entry";
            case 26:
                return "Auction Slot";
            case 27:
                return "Auth Account";
            case 28:
                return "XChain Claim Proof Sig.";
            case 29:
                return "XChain Create Account Proof Sig.";
            case 30:
                return "XChain Claim Attestation Collection Element";
            case 31:
                return "XChain Create Account Attestation Collection Element";
        }
    }

    if (field->data_type == STI_ARRAY) {
        switch (field->id) {
            // array of objects
            // ARRAY/1 is reserved for end of array
            case 3:
                return "Signers";
            case 4:
                return "Signer Entries";
            case 5:
                return "Template";
            case 6:
                return "Necessary";
            case 7:
                return "Sufficient";
            case 8:
                return "AffectedNodes";
            case 9:
                return "Memos";
            case 10:
                return "NFTokens";
            // break
            case 12:
                return "Vote Slots";
            // break
            case 16:
                return "Majorities";
            case 17:
                return "Disabled Validators";
            // break
            case 21:
                return "XChain Claim Attestations";
            case 22:
                return "XChain Create Account Attestations";
            // break
            case 25:
                return "Auth Accounts";
        }
    }

    if (field->data_type == STI_UINT8) {
        switch (field->id) {
            // 8-bit integers
            case 16:
                return "Tick Size";
        }
    }

    if (field->data_type == STI_PATHSET) {
        switch (field->id) {
            case 1:
                return "Paths";
        }
    }

    if (field->data_type == STI_CURRENCY) {
        switch (field->id) {
            case 1:
                return "Currency";
        }
    }

    if (field->data_type == STI_ISSUE) {
        switch (field->id) {
            case 1:
                return "Locking Chain Issue";
            case 2:
                return "Issuing Chain Issue";
            case 3:
                return "Asset";
            case 4:
                return "Asset 2";
        }
    }

    if (field->data_type == STI_XCHAIN_BRIDGE) {
        switch (field->id) {
            case 1:
                return "XChainBridge";
        }
    }

    // Default case
    return "Unknown";
}

bool is_field_hidden(field_t *field) {
    HIDE(STI_UINT32, XRP_UINT32_SEQUENCE);
    HIDE(STI_UINT32, XRP_UINT32_LAST_LEDGER_SEQUENCE);
    HIDE(STI_VL, XRP_VL_SIGNING_PUB_KEY);

    if (field->data_type == STI_ARRAY || field->data_type == STI_OBJECT ||
        field->data_type == STI_PATHSET) {
        // Field is only used to instruct parsing code how to handle following fields: don't show
        return true;
    }

    if (is_flag_hidden(field)) {
        return true;
    }

    return false;
}
