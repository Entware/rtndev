#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=p0f
PKG_VERSION:=3.08b
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=http://lcamtuf.coredump.cx/p0f3/releases/
PKG_MD5SUM:=984aad167d6f5849a5b319e11c81e2b1

include $(INCLUDE_DIR)/package.mk

define Package/p0f
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libpcap
	TITLE:=Purely passive traffic fingerprinting
	URL:=http://lcamtuf.coredump.cx/p0f3
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/p0f/description
 P0f is a tool that utilizes an array of sophisticated, purely passive traffic
 fingerprinting mechanisms to identify the players behind any incidental TCP/IP
 communications (often as little as a single normal SYN) without interfering in
 any way.
endef

define Package/p0f/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/p0f $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/p0f.fp $(1)/opt/share
endef

$(eval $(call BuildPackage,p0f))
