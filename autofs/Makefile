# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2022 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=autofs
PKG_VERSION:=5.1.8
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://mirrors.edge.kernel.org/pub/linux/daemons/autofs/v5
PKG_HASH:=b33d1059855664b20eeda26f3e28ff518fb0c3d58f565570af2ae569dc73c0fd

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-2.0-only
PKG_LICENSE_FILES:=COPYING COPYRIGHT

PKG_INSTALL:=1

PKG_CONFIG_DEPENDS:= \
	CONFIG_AUTOFS_OPENLDAP \
	CONFIG_AUTOFS_SASL \
	CONFIG_AUTOFS_TIRPC

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/autofs
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Filesystem
  TITLE:=A kernel-based automounter for Linux
  URL:=https://mirrors.edge.kernel.org/pub/linux/daemons/autofs/
  DEPENDS:= \
	+AUTOFS_OPENLDAP:libopenldap \
	+AUTOFS_OPENLDAP:libxml2 \
	+AUTOFS_SASL:libsasl2 \
	+AUTOFS_TIRPC:libtirpc
endef

define Package/autofs/description
  Autofs controls the operation of the automount daemons. The automount
  daemons automatically mount filesystems when they are used and unmount
  them after a period of inactivity.
endef

define Package/autofs/conffiles
/opt/etc/autofs.conf
/opt/etc/auto.master
/opt/etc/auto.misc
$(if CONFIG_AUTOFS_OPENLDAP,/opt/etc/autofs_ldap_auth.conf)
endef

define Package/autofs/config
  source "$(SOURCE)/Config.in"
endef

CONFIGURE_ARGS += \
	--enable-sloppy-mount \
	--enable-no-canon-umount \
	--with-confdir="/opt/etc/default" \
	--with-fifodir="/opt/var/run" \
	--with-flagdir="/opt/var/run" \
	--with-mapdir="/opt/etc" \
	--with-path="$$$$PATH" \
	--without-hesiod \
	--with$(if $(CONFIG_AUTOFS_OPENLDAP),,out)-openldap \
	--with$(if $(CONFIG_AUTOFS_SASL),,out)-sasl \
	--with$(if $(CONFIG_AUTOFS_TIRPC),,out)-libtirpc \
	--without-systemd

CONFIGURE_VARS += \
	initdir='/opt/etc/init.d' \
	piddir='/opt/var/run' \
	E2FSCK='/opt/sbin/fsck.ext2' \
	E3FSCK='/opt/sbin/fsck.ext3' \
	E4FSCK='/opt/sbin/fsck.ext4' \
	MOUNT='/opt/bin/mount' \
	MOUNT_NFS='/opt/sbin/mount.nfs' \
	UMOUNT='/opt/bin/umount' \
	RANLIB="$(TOOLCHAIN_DIR)/bin/$(TARGET_RANLIB)" \
	ac_cv_path_KRB5_CONFIG=''

define Package/autofs/install
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/samples/autofs.conf.default \
		$(1)/opt/etc/autofs.conf
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/samples/auto.master $(1)/opt/etc
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/samples/auto.misc $(1)/opt/etc

ifeq ($(CONFIG_AUTOFS_OPENLDAP),y)
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/samples/autofs_ldap_auth.conf \
		$(1)/opt/etc
endif

	$(INSTALL_DIR) $(1)/opt/lib/autofs
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libautofs.so $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/autofs/*.so $(1)/opt/lib/autofs

	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/automount $(1)/opt/sbin
endef

$(eval $(call BuildPackage,autofs))
