#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=istgt
PKG_VERSION:=20141125
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://shell.peach.ne.jp/~aoyama/wordpress/download
PKG_MD5SUM:=95dc647d7bf69f10bb6b09ae9d63f0c5

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/istgt
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libopenssl +libpthread
	TITLE:=An iSCSI target implementation
	URL:=http://www.peach.ne.jp/archives/istgt/
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/istgt/description
 This is a BSD Port of istgt, which  provides iSCSI target side protocol
 (refer to RFC3720 about iSCSI) and SPC-3 (SCSI Primary Commands - 3)
 based logical unit emulation.
endef

CONFIGURE_ARGS += \
	--with-mediadir=/opt/var \

define Package/istgt/conffiles
/opt/etc/istgt/auth.conf
/opt/etc/istgt/istgt.conf
/opt/etc/istgt/istgtcontrol.conf
endef

define Package/istgt/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/istgt $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/istgtcontrol $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/istgt
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/istgt/{auth,istgt,istgt.large,istgtcontrol}.conf.sample $(1)/opt/etc/istgt
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S13istgt $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,istgt))
