# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2020-2025 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=isync
PKG_VERSION:=1.5.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)/$(PKG_VERSION)
PKG_HASH:=28cc90288036aa5b6f5307bfc7178a397799003b96f7fd6e4bd2478265bb22fa

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/isync
	SECTION:=mail
	CATEGORY:=Mail
	DEPENDS:=+openssl-util +libsasl2 +libdb47
	TITLE:=mailbox synchronizer
	URL:=http://isync.sourceforge.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/isync/description
 isync is a command line application which synchronizes mailboxes; currently
 Maildir and IMAP4 mailboxes are supported. New messages, message deletions and
 flag changes can be propagated both ways. isync is suitable for use in
 IMAP-disconnected mode.
endef

define Package/isync/install
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
endef

$(eval $(call BuildPackage,isync))
