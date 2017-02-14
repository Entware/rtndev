#
# Copyright (C) 2012 Erinome.net
# Copyright (C) 2013-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2009

include $(TOPDIR)/rules.mk

PKG_NAME:=cadaver
PKG_VERSION:=0.23.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.webdav.org/cadaver
PKG_MD5SUM:=502ecd601e467f8b16056d2acca39a6f

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/cadaver
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libncurses +libexpat +libneon +libopenssl +libreadline
	TITLE:=Command-line WebDAV client
	URL:=http://www.webdav.org/cadaver/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/cadaver/description
 cadaver is a command-line WebDAV client for Unix. It supports file upload, download, 
 on-screen display, namespace operations (move/copy), collection creation and deletion, and locking operations.
endef

CONFIGURE_ARGS += \
	--prefix=/opt \
	--with-libs=$(STAGING_DIR)/opt \
	--with-ssl=openssl \
	--disable-nls \

TARGET_CPPFLAGS += -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_GNU_SOURCE

define Package/cadaver/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/cadaver $(1)/opt/bin
endef

$(eval $(call BuildPackage,cadaver))
