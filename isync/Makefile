#
# Copyright (C) 2020-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=isync
PKG_VERSION:=1.4.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)/$(PKG_VERSION)
PKG_HASH:=b4c720745bda3447fbd5b9f71783b23f699a55295917ae7586ee5c22e91b9708

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
