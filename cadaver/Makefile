#
# Copyright (C) 2012 Erinome.net
# Copyright (C) 2013-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cadaver
PKG_VERSION:=0.24
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://notroj.github.io/cadaver
PKG_HASH:=46cff2f3ebd32cd32836812ca47bcc75353fc2be757f093da88c0dd8f10fd5f6

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/cadaver
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libexpat +libncurses +libneon +libopenssl +libreadline +zlib
	TITLE:=Command-line WebDAV client
	URL:=https://notroj.github.io/cadaver/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cadaver/description
 cadaver is a command-line WebDAV client for Unix. It supports file upload,
 download, on-screen display, namespace operations (move/copy), collection
 creation and deletion, and locking operations.
endef

CONFIGURE_ARGS += \
	--disable-nls \
	--with-ssl=openssl \
	--without-gssapi

TARGET_CPPFLAGS += -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_GNU_SOURCE

define Package/cadaver/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/cadaver $(1)/opt/bin
endef

$(eval $(call BuildPackage,cadaver))
