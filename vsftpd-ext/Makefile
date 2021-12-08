#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=vsftpd-ext
PKG_VERSION:=3.0.5
PKG_RELEASE:=1

PKG_SOURCE:=vsftpd-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://vsftpd.devnet.ru/files/$(PKG_VERSION)
PKG_HASH:=26b602ae454b0ba6d99ef44a09b6b9e0dfa7f67228106736df1f278c70bc91d3

include $(INCLUDE_DIR)/package.mk

PKG_UNPACK:=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xzf $(DL_DIR)/$(PKG_SOURCE)

define Package/vsftpd-ext
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	TITLE:=A fast and secure FTP server
	URL:=http://vsftpd.devnet.ru
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/vsftpd-ext/descriptio
 vsftpd-ext is a GPL licensed FTP server for UNIX systems, including Linux.
endef

define Package/vsftpd-ext/conffiles
/opt/etc/vsftpd/vsftpd.conf
endef

TARGET_CFLAGS += -Wno-error

ifeq ($(or $(CONFIG_GCC_USE_VERSION_8),$(CONFIG_GCC_USE_VERSION_9)),y)
TARGET_CFLAGS += -Wno-error=stringop-truncation
endif

define Package/vsftpd-ext/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/vsftpd $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/vsftpd
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/vsftpd.conf $(1)/opt/etc/vsftpd
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S49vsftpd $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/share/empty
endef

$(eval $(call BuildPackage,vsftpd-ext))
